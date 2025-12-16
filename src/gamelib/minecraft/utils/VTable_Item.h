#pragma once

#include <utils/Types.h>

#include "../client/resource/shared_ptr.h"

#include "Common.h"
#include "InteractionHand.h"
#include "VTable.h"

namespace mc {
    class ItemInstance;
    class CompoundTag;
    class ItemToolTipDataHolder;
    class Player;
    class BlockState;

    class VTable_Item : public VTable {
    public:
        MC_VFUNC(void, Item, getDefaultInstance, const mc_boost::shared_ptr<ItemInstance> &);
        MC_VFUNC(void, Item, verifyTagAfterLoad, CompoundTag *);
        MC_VFUNC(void, Item, GetUseTooltip, const ItemToolTipDataHolder &);
        MC_VFUNC(void, Item, __dt__Fv, bool);
        MC_VFUNC(void, Item, useOn, const mc_boost::shared_ptr<Player> &, const BlockPos &, InteractionHand::EInteractionHand, Direction *, float,
                 float, float, bool);
        MC_VFUNC(void, Item, getDestroySpeed, const mc_boost::shared_ptr<ItemInstance> &, BlockState *);
        MC_VFUNC(void, Item, TestUse, Level *, const mc_boost::shared_ptr<Player> &, InteractionHand::EInteractionHand);
        MC_VFUNC(void, Item, use__FP5LevelQ2_5boost25shared_ptr__tm__8_6PlayerQ2_15InteractionHand16EInteractionHand);
        MC_VFUNC(void, Item, finishUsingItem__F35not_null_ptr__tm__15_12ItemInstanceP5LevelQ2_5boost33shared_ptr__tm__15_12LivingEntity);
        MC_VFUNC(void, Item, getMaxStackSize__Fv);
        MC_VFUNC(void, Item, getLevelDataForAuxValue__Fi);
        MC_VFUNC(bool, Item, hurtEnemy, const mc_boost::shared_ptr<ItemInstance> &, const mc_boost::shared_ptr<LivingEntity> &,
                 const mc_boost::shared_ptr<LivingEntity> &);
        MC_VFUNC(bool, Item, mineBlock, const mc_boost::shared_ptr<ItemInstance> &, Level *, const BlockState *, const BlockPos &,
                 mc_boost::shared_ptr<LivingEntity> &);
        MC_VFUNC(void, Item, getAttackDamage__FQ2_5boost25shared_ptr__tm__8_6Entity);
        MC_VFUNC(void, Item, canDestroySpecial__FPC10BlockState);
        MC_VFUNC(
                void, Item,
                interactEnemy__F35not_null_ptr__tm__15_12ItemInstanceQ2_5boost25shared_ptr__tm__8_6PlayerQ2_5boost33shared_ptr__tm__15_12LivingEntityQ2_15InteractionHand16EInteractionHand);
        MC_VFUNC(bool, Item, isHandEquipped__Fv);
        MC_VFUNC(bool, Item, isMirroredArt__Fv);
        MC_VFUNC(void, Item, getDescriptionId__Fi);
        MC_VFUNC(void, Item, getDescriptionId__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(void, Item, getUseDescriptionId__Fv);
        MC_VFUNC(void, Item, shouldOverrideMultiplayerNBT__Fv);
        MC_VFUNC(void, Item, getUseDescriptionId__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(void, Item, inventoryTick, mc_boost::shared_ptr<ItemInstance> &, Level *, mc_boost::shared_ptr<Entity> &, int, bool);
        MC_VFUNC(void, Item, getColor__F35not_null_ptr__tm__15_12ItemInstancei);
        MC_VFUNC(bool, Item, isComplex__Fv);
        MC_VFUNC(void, Item, onCraftedBy__F35not_null_ptr__tm__15_12ItemInstanceP5LevelQ2_5boost25shared_ptr__tm__8_6Player);
        MC_VFUNC(int, Item, getUseDuration, const mc_boost::shared_ptr<ItemInstance> &);
        MC_VFUNC(void, Item, getUseAnimation__CF36not_null_ptr__tm__16_C12ItemInstance);
        MC_VFUNC(Item *, Item, releaseUsing, const mc_boost::shared_ptr<ItemInstance> &, Level *, const mc_boost::shared_ptr<LivingEntity> &, int);
        MC_VFUNC(
                void, Item,
                appendHoverText__F35not_null_ptr__tm__15_12ItemInstanceQ2_5boost25shared_ptr__tm__8_6PlayerPQ2_3std66vector__tm__52_10HtmlStringQ2_3std30allocator__tm__13_10HtmlStringb);
        MC_VFUNC(void, Item, getName__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(bool, Item, isFoil__F35not_null_ptr__tm__15_12ItemInstance, mc_boost::shared_ptr<ItemInstance>);
        MC_VFUNC(void, Item, getRarity__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(bool, Item, isEnchantable__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(void, Item, getEnchantmentValue__Fv);
        MC_VFUNC(void, Item, mayBePlacedInAdventureMode__Fv);
        MC_VFUNC(bool, Item, isValidRepairItem__F35not_null_ptr__tm__15_12ItemInstanceT1);
        MC_VFUNC(void, Item, getDefaultAttributeModifiers__FPC13EquipmentSlot);
        MC_VFUNC(void, Item, registerIcons__FP12IconRegister);
        MC_VFUNC(void, Item, hasMultipleSpriteLayers__Fv);
        MC_VFUNC(void, Item, getLayerIcon__FiT135not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(void, Item, getIconType__Fv);
        MC_VFUNC(void, Item, getIcon__Fi);
        MC_VFUNC(void, Item, getIcon__F35not_null_ptr__tm__15_12ItemInstance);
        MC_VFUNC(void, Item, GetArmorType__Fv);
        MC_VFUNC(void, Item, GetOverrideCount__Fv);
        MC_VFUNC(void, Item, GetOverrideCountColour__Fv);
        MC_VFUNC(void, Item, GetOverrideCountIcon__F35not_null_ptr__tm__15_12ItemInstance);
    };
} // namespace mc