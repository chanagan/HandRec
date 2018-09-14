//
// Created by Chris Hanagan on 9/14/18.
//

#include <wx/wx.h>
#include "InvStockItem.h"
#include "Inventory.h"

InvStockItem::InvStockItem(Inventory * inv_lines) {
    inventory = inv_lines;

}
size_t InvStockItem::SetFirst(size_t line_idx)
{
    size_t wrk_idx = line_idx;

    line_in = inventory->inv_line(wrk_idx);
    return wrk_idx;
}
