/* Infineon WLAN driver: BT shared SDIO implement
 *
 * copyright 2019, 2022 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 * This software, including source code, documentation and related materials
 * ("Software") is owned by Cypress Semiconductor Corporation or one of its
 * affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license agreement
 * accompanying the software package from which you obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software source code
 * solely for use in connection with Cypress's integrated circuit products.
 * Any reproduction, modification, translation, compilation, or representation
 * of this Software except as specified above is prohibited without
 * the expresswritten permission of Cypress.
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * Cypress reserves the right to make changes to the Software without notice.
 * Cypress does not assume any liability arising out of the application or
 * use of the Software or any product or circuit described in the Software.
 * Cypress does not authorize its products for use in any products where a malfunction
 * or failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product").
 * By including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing so
 * agrees to indemnify Cypress against all liability.
 */

#ifndef	BT_SHARED_SDIO_IFX_H
#define	BT_SHARED_SDIO_IFX_H

#ifdef CONFIG_INFFMAC_BT_SHARED_SDIO

bool inf_btsdio_inited(struct brcmf_bus *bus_if);
bool inf_btsdio_is_active(struct brcmf_bus *bus_if);
bool inf_btsdio_set_bt_reset(struct brcmf_bus *bus_if);

int inf_bus_attach(u32 ver, void *info);
void inf_bus_detach(struct brcmf_bus *bus_if);
u8 inf_bus_reg_readb(struct brcmf_bus *bus_if, u8 fn, u32 addr, int *err);
void inf_bus_reg_writeb(struct brcmf_bus *bus_if, u8 fn, u32 addr, u8 val, int *err);
u32 inf_bus_reg_readl(struct brcmf_bus *bus_if, u32 addr, int *err);
void inf_bus_reg_writel(struct brcmf_bus *bus_if, u32 addr, u32 val, int *err);
int inf_bus_recv_buf(struct brcmf_bus *bus_if, u8 *buf, u32 nbytes);
int inf_bus_send_buf(struct brcmf_bus *bus_if, u8 *buf, u32 nbytes);
int inf_bus_membytes(struct brcmf_bus *bus_if, bool set, u32 address, u8 *data, u32 size);
int inf_bus_set_blocksz(struct brcmf_bus *bus_if, u16 blocksz);
int inf_bus_clk_enable(struct brcmf_bus *bus_if);
int inf_bus_clk_disable(struct brcmf_bus *bus_if);

void inf_btsdio_init(struct brcmf_bus *bus_if);
void inf_btsdio_deinit(struct brcmf_bus *bus_if);
void inf_btsdio_debugfs_create(struct brcmf_pub *drvr);

#else

#define inf_btsdio_inited(bus_if) ((void)(bus_if), false)
#define inf_btsdio_is_active(bus_if) ((void)(bus_if), false)
#define inf_btsdio_set_bt_reset(bus_if) ((void)(bus_if), false)

#define inf_bus_attach(ver, info) ((void)(ver), (void)(info), -1)
#define inf_bus_detach(bus_if) ((void)(bus_if))
#define inf_bus_reg_readb(bus_if, fn, addr, err) \
((void)(bus_if), (void)(fn), (void)(addr), (void)(err), 0)
#define inf_bus_reg_writeb(bus_if, fn, addr, val, err) \
((void)(bus_if), (void)(fn), (void)(addr), (void)(val), (void)(err))
#define inf_bus_reg_readl(bus_if, addr, err) ((void)(bus_if), (void)(addr), (void)(err), 0)
#define inf_bus_reg_writel(bus_if, addr, val, err) \
((void)(bus_if), (void)(addr), (void)(val), (void)(err))
#define inf_bus_recv_buf(bus_if, buf, nbytes) ((void)(bus_if), (void)(buf), (void)(nbytes), -1)
#define inf_bus_send_buf(bus_if, buf, nbytes) ((void)(bus_if), (void)(buf), (void)(nbytes), -1)
#define inf_bus_membytes(bus_if, set, address, data, size) \
((void)(bus_if), (void)(set), (void)(address), (void)(data), (void)(size), -1)
#define inf_bus_set_blocksz(bus_if, blocksz) ((void)(bus_if), (void)(blocksz), -1)
#define inf_bus_clk_enable(bus_if) ((void)(bus_if), -1)
#define inf_bus_clk_disable(bus_if) ((void)(bus_if), -1)

#define inf_btsdio_init(bus_if) ((void)(bus_if))
#define inf_btsdio_deinit(bus_if) ((void)(bus_if))
#define inf_btsdio_debugfs_create(drvr) ((void)(drvr))

#endif /* CONFIG_INFFMAC_BT_SHARED_SDIO */

#endif /* BT_SHARED_SDIO_IFX */
