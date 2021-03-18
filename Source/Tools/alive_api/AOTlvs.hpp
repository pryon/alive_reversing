#pragma once

#include "TlvObjectBase.hpp"
#include "../AliveLibAO/HoistRocksEffect.hpp"
#include "../AliveLibAO/Abe.hpp"
#include "../AliveLibAO/Door.hpp"
#include "../AliveLibAO/Switch.hpp"
#include "../AliveLibAO/DoorLight.hpp"
#include "../AliveLibAO/ElectricWall.hpp"
#include "../AliveLibAO/Well.hpp"
#include "../AliveLibAO/Slig.hpp"
#include "../AliveLibAO/SecurityOrb.hpp"
#include "../AliveLibAO/FallingItem.hpp"
#include "../AliveLibAO/Mine.hpp"
#include "../AliveLibAO/Dove.hpp"
#include "../AliveLibAO/UXB.hpp"
#include "../AliveLibAO/HintFly.hpp"
#include "../AliveLibAO/Bat.hpp"
#include "../AliveLibAO/ShadowZone.hpp"
#include "../AliveLibAO/BellHammer.hpp"
#include "../AliveLibAO/IdSplitter.hpp"
#include "../AliveLibAO/PullRingRope.hpp"
#include "../AliveLibAO/MusicTrigger.hpp"
#include "../AliveLibAO/Elum.hpp"
#include "../AliveLibAO/LiftPoint.hpp"
#include "../AliveLibAO/MovingBomb.hpp"
#include "../AliveLibAO/Mudokon.hpp"
#include "../AliveLibAO/MeatSaw.hpp"
#include "../AliveLibAO/LCDScreen.hpp"
#include "../AliveLibAO/InvisibleSwitch.hpp"
#include "../AliveLibAO/TrapDoor.hpp"
#include "../AliveLibAO/BirdPortal.hpp"
#include "../AliveLibAO/BoomMachine.hpp"
#include "../AliveLibAO/Slog.hpp"
#include "../AliveLibAO/ChimeLock.hpp"
#include "../AliveLibAO/FlintLockFire.hpp"
#include "../AliveLibAO/LiftMover.hpp"
#include "../AliveLibAO/Scrab.hpp"
#include "../AliveLibAO/SlogSpawner.hpp"
#include "../AliveLibAO/Rock.hpp"
#include "../AliveLibAO/SlogHut.hpp"
#include "../AliveLibAO/SecurityClaw.hpp"
#include "../AliveLibAO/SecurityDoor.hpp"
#include "../AliveLibAO/TimedMine.hpp"

#define CTOR_AO(className, objectTypeName, tlvType)  className(TypesCollection& globalTypes, AO::Path_TLV* pTlv = nullptr) : TlvObjectBaseAO(tlvType, objectTypeName, pTlv)

namespace AO
{
    struct Path_ContinueZone : public Path_TLV
    {
        int field_10_zone_number;
    };

    struct Path_StartController : public Path_TLV
    {
        // No fields
    };

    struct Path_InvisibleZone : public Path_TLV
    {
        // No fields
    };

    struct Path_DeathDrop : public Path_TLV
    {
        __int16 animation;
        __int16 sound;
        __int16 id;
        __int16 action;
        int set_value;
    };

    struct Path_ElumStart : public Path_TLV
    {
        // No fields
    };

    struct Path_ElumWall : public Path_TLV
    {
        // No fields
    };
}

namespace AOTlvs
{
    struct Path_Door : public TlvObjectBaseAO<AO::Path_Door>
    {
        void AddTypes(TypesCollection& types) override
        {
            types.AddEnum<AO::DoorStates>("Enum_DoorStates",
                {
                    {AO::DoorStates::eOpen_0, "Open"},
                    {AO::DoorStates::eClosed_1, "Closed"},
                    {AO::DoorStates::eOpening_2, "Opening"},
                    {AO::DoorStates::eClosing_3, "Closing"},
                });
        }

        CTOR_AO(Path_Door, "Door", AO::TlvTypes::Door_6)
        {
            ADD("Level", mTlv.field_18_level);
            ADD("Path", mTlv.field_1A_path);
            ADD("Camera", mTlv.field_1C_camera);
            ADD("Scale", mTlv.field_1E_scale);
            ADD("DoorNumber", mTlv.field_20_door_number);
            ADD("Id", mTlv.field_22_id);
            ADD("TargetDoorNumber", mTlv.field_24_target_door_number);
            ADD("StartState", mTlv.field_26_start_state);
            ADD("DoorClosed", mTlv.field_28_door_closed);
            ADD("Hub1", mTlv.field_2A_hub1);
            ADD("Hub2", mTlv.field_2A_hub2);
            ADD("Hub3", mTlv.field_2A_hub3);
            ADD("Hub4", mTlv.field_2A_hub4);
            ADD("Hub5", mTlv.field_2A_hub5);
            ADD("Hub6", mTlv.field_2A_hub6);
            ADD("Hub7", mTlv.field_2A_hub7);
            ADD("Hub8", mTlv.field_2A_hub8);
            ADD("WipeEffect", mTlv.field_3A_wipe_effect);
            ADD("MovieNumber", mTlv.field_3C_movie_number);
            ADD("XOffset", mTlv.field_3E_x_offset);
            ADD("YOffset", mTlv.field_40_y_offset);
            ADD("WipeXOrg", mTlv.field_42_wipe_x_org);
            ADD("WipeYOrg", mTlv.field_44_wipe_y_org);
            ADD("AbeDirection", mTlv.field_46_abe_direction);
        }
    };

    struct Path_ContinuePoint : public TlvObjectBaseAO<AO::Path_ContinuePoint>
    {
        CTOR_AO(Path_ContinuePoint, "ContinuePoint",  AO::TlvTypes::ContinuePoint_0)
        {
            ADD("ZoneNumber", mTlv.field_18_zone_number);
            ADD("ClearFromId", mTlv.field_1A_clear_from_id);
            ADD("ClearToId", mTlv.field_1C_clear_to_id);
            ADD("ElumRestarts", mTlv.field_1E_elum_restarts);
            ADD("AbeSpawnDirection", mTlv.field_20_abe_direction);
        }
    };

    struct Path_Hoist : public TlvObjectBaseAO<AO::Path_Hoist>
    {
        void AddTypes(TypesCollection& types) override
        {
            types.AddEnum<AO::Path_Hoist::Type>("Enum_HoistType",
                {
                    {AO::Path_Hoist::Type::eNextEdge, "next_edge"},
                    {AO::Path_Hoist::Type::eNextFloor, "next_floor"},
                    {AO::Path_Hoist::Type::eOffScreen, "off_screen"},
                });

            types.AddEnum<AO::Path_Hoist::EdgeType>("Enum_HoistEdgeType",
                {
                    {AO::Path_Hoist::EdgeType::eBoth, "both"},
                    {AO::Path_Hoist::EdgeType::eLeft, "left"},
                    {AO::Path_Hoist::EdgeType::eRight, "right"},
                });
        }

        CTOR_AO(Path_Hoist, "Hoist", AO::TlvTypes::Hoist_3)
        {
            ADD("HoistType", mTlv.field_18_hoist_type);
            ADD("HoistEdgeType", mTlv.field_1A_edge_type);
            ADD("Id", mTlv.field_1C_id);
        }
    };

    struct Path_Change : public TlvObjectBaseAO<AO::Path_ChangeTLV>
    {
        CTOR_AO(Path_Change, "PathTransition", AO::TlvTypes::PathTransition_1)
        {
            ADD("Level", mTlv.field_18_level);
            ADD("HoistEdgeType", mTlv.field_1A_path);
            ADD("Camera", mTlv.field_1C_camera);
            ADD("Movie", mTlv.field_1E_movie); // TODO: Enum
            ADD("Wipe", mTlv.field_20_wipe); // TODO: Enum
            ADD("Scale", mTlv.field_22_scale); // TODO: Enum
        }
    };

    struct Path_Switch : public TlvObjectBaseAO<AO::Path_Switch>
    {
        CTOR_AO(Path_Switch, "Switch", AO::TlvTypes::Switch_26)
        {
            ADD("TriggerObject", mTlv.field_18_trigger_object);
            ADD("TriggerAction", mTlv.field_1A_trigger_object_action);
            ADD("Scale", mTlv.field_1C_scale);
            ADD("OnSound", mTlv.field_1E_on_sound); // TODO: Enum
            ADD("OffSound", mTlv.field_20_off_sound); // TODO: Enum
            ADD("SoundDirection", mTlv.field_22_sound_direction); // TODO: Enum
        }
    };

    struct Path_LightEffect : public TlvObjectBaseAO<AO::Path_LightEffect>
    {
        void AddTypes(TypesCollection& types) override
        {
            types.AddEnum<AO::Path_LightEffect::Type>("Enum_LightType",
                {
                    {AO::Path_LightEffect::Type::Star_0, "Star"},
                    {AO::Path_LightEffect::Type::RedGlow_1, "RedGlow"},
                    {AO::Path_LightEffect::Type::GreenGlow_2, "GreenGlow"},
                    {AO::Path_LightEffect::Type::FlintGlow_3, "FlintGlow"},
                    {AO::Path_LightEffect::Type::Switchable_RedGreenDoorLights_4, "RedGreenDoorLight"},
                    {AO::Path_LightEffect::Type::Switchable_RedGreenHubLight_5, "RedGreenHubLight"},
                });
        }

        CTOR_AO(Path_LightEffect, "LightEffect", AO::TlvTypes::LightEffect_106)
        {
            ADD("Type", mTlv.field_18_type);
            ADD("Size", mTlv.field_1A_size);
            ADD("Id", mTlv.field_1C_id);
            ADD("FlipX", mTlv.field_1E_flip_x);
        }
    };

    struct Path_ElectricWall : public TlvObjectBaseAO<AO::Path_ElectricWall>
    {
        CTOR_AO(Path_ElectricWall, "ElectricWall", AO::TlvTypes::ElectricWall_67)
        {
            ADD("Scale", mTlv.field_18_scale);
            ADD("Id", mTlv.field_1A_id);
            ADD("State", mTlv.field_1C_start_state); // TODO: Enum
        }
    };

    struct Path_ContinueZone : public TlvObjectBaseAO<AO::Path_ContinueZone>
    {
        CTOR_AO(Path_ContinueZone, "ContinueZone", AO::TlvTypes::ContinueZone_2)
        {
            ADD("ZoneNumber", mTlv.field_10_zone_number);
        }
    };

    struct Path_StartController : public TlvObjectBaseAO<AO::Path_StartController>
    {
        CTOR_AO(Path_StartController, "StartController", AO::TlvTypes::StartController_28)
        {
            // No fields
        }
    };

    struct Path_Edge : public TlvObjectBaseAO<AO::Path_Edge>
    {
        void AddTypes(TypesCollection& types) override
        {
            types.AddEnum<AO::Path_Edge::Type>("Enum_EdgeType",
                {
                    {AO::Path_Edge::Type::eLeft, "left"},
                    {AO::Path_Edge::Type::eRight, "right"},
                    {AO::Path_Edge::Type::eBoth, "both"},
                });
        }

        CTOR_AO(Path_Edge, "Edge", AO::TlvTypes::Edge_4)
        {
            ADD("type", mTlv.field_18_type);
            ADD("can_grab", mTlv.field_1A_can_grab);
        }
    };

    struct Path_WellLocal : public TlvObjectBaseAO<AO::Path_WellLocal>
    {
        CTOR_AO(Path_WellLocal, "WellLocal", AO::TlvTypes::WellLocal_11)
        {
            ADD("on_dx", mTlv.field_28_on_dx);
            ADD("on_dy", mTlv.field_2A_on_dy);
            ADD("emit_leaves", mTlv.field_2C_emit_leaves);
            ADD("leaf_x", mTlv.field_2E_leaf_x);
            ADD("leaf_y", mTlv.field_30_leaf_y);
        }
    };

    struct Path_WellExpress : public TlvObjectBaseAO<AO::Path_WellExpress>
    {
        CTOR_AO(Path_WellExpress, "WellExpress", AO::TlvTypes::WellExpress_45)
        {
            ADD("off_camera", mTlv.field_28_off_camera);
            ADD("off_well_id", mTlv.field_2A_off_well_id);
            ADD("on_level", mTlv.field_2C_on_level);
            ADD("on_path", mTlv.field_2E_on_path);
            ADD("on_camera", mTlv.field_30_on_camera);
            ADD("on_well_id", mTlv.field_32_on_well_id);
            ADD("emit_leaves", mTlv.field_34_emit_leaves);
            ADD("leaf_x", mTlv.field_36_leaf_x);
            ADD("leaf_y", mTlv.field_38_leaf_y);
            ADD("movie_id", mTlv.field_3A_movie_id);
        }
    };

    struct Path_InvisibleZone : public TlvObjectBaseAO<AO::Path_InvisibleZone>
    {
        CTOR_AO(Path_InvisibleZone, "InvisibleZone", AO::TlvTypes::InvisibleZone_58)
        {
            // No fields
        }
    };

    struct Path_EnemyStopper : public TlvObjectBaseAO<AO::Path_EnemyStopper>
    {
        void AddTypes(TypesCollection& types) override
        {
            types.AddEnum<AO::Path_EnemyStopper::StopDirection>("Enum_StopDirection",
                {
                    {AO::Path_EnemyStopper::StopDirection::Left_0, "left"},
                    {AO::Path_EnemyStopper::StopDirection::Right_1, "right"},
                    {AO::Path_EnemyStopper::StopDirection::Both_2, "both"},
                });
        }

        CTOR_AO(Path_EnemyStopper, "EnemyStopper", AO::TlvTypes::EnemyStopper_79)
        {
            ADD("direction", mTlv.field_18_direction);
            ADD("id", mTlv.field_1A_id);
        }
    };

    struct Path_Slig : public TlvObjectBaseAO<AO::Path_Slig>
    {
        void AddTypes(TypesCollection& types) override
        {
            types.AddEnum<AO::Path_Slig::StartState>("Enum_SligStartState",
                {
                    {AO::Path_Slig::StartState::Listening_0, "listening"},
                    {AO::Path_Slig::StartState::Paused_1, "paused"},
                    {AO::Path_Slig::StartState::Sleeping_2, "sleeping"},
                    {AO::Path_Slig::StartState::Chase_3, "chase"},
                    {AO::Path_Slig::StartState::GameEnder_4, "game_ender"},
                    {AO::Path_Slig::StartState::Paused_5, "paused"},
                });
        }

        CTOR_AO(Path_Slig, "Slig", AO::TlvTypes::Slig_24)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("start_state", mTlv.field_1A_start_state);
            ADD("pause_time", mTlv.field_1C_pause_time);
            ADD("pause_left_min", mTlv.field_1E_pause_left_min);
            ADD("pause_left_max", mTlv.field_20_pause_left_max);
            ADD("pause_right_min", mTlv.field_22_pause_right_min);
            ADD("pause_right_max", mTlv.field_24_pause_right_max);
            ADD("chal_type", mTlv.field_26_chal_type);
            ADD("chal_time", mTlv.field_28_chal_time);
            ADD("number_of_times_to_shoot", mTlv.field_2A_number_of_times_to_shoot);
            ADD("unknown", mTlv.field_2C_unknown);
            ADD("code1", mTlv.field_2E_code1);
            ADD("code2", mTlv.field_30_code2);
            ADD("chase_abe", mTlv.field_32_chase_abe);
            ADD("start_direction", mTlv.field_34_start_direction);
            ADD("panic_timeout", mTlv.field_36_panic_timeout);
            ADD("num_panic_sounds", mTlv.field_38_num_panic_sounds);
            ADD("panic_sound_timeout", mTlv.field_3A_panic_sound_timeout);
            ADD("stop_chase_delay", mTlv.field_3C_stop_chase_delay);
            ADD("time_to_wait_before_chase", mTlv.field_3E_time_to_wait_before_chase);
            ADD("slig_id", mTlv.field_40_slig_id);
            ADD("listen_time", mTlv.field_42_listen_time);
            ADD("percent_say_what", mTlv.field_44_percent_say_what);
            ADD("percent_beat_mud", mTlv.field_46_percent_beat_mud);
            ADD("talk_to_abe", mTlv.field_48_talk_to_abe);
            ADD("dont_shoot", mTlv.field_4A_dont_shoot);
            ADD("z_shoot_delay", mTlv.field_4C_z_shoot_delay);
            ADD("stay_awake", mTlv.field_4E_stay_awake);
            ADD("disable_resources", mTlv.field_50_disable_resources.Raw().all);
            ADD("noise_wake_up_distance", mTlv.field_52_noise_wake_up_distance);
            ADD("id", mTlv.field_54_id);
        }
    };

    struct Path_DeathDrop : public TlvObjectBaseAO<AO::Path_DeathDrop>
    {
        CTOR_AO(Path_DeathDrop, "DeathDrop", AO::TlvTypes::DeathDrop_5)
        {
            ADD("animation", mTlv.animation);
            ADD("sound", mTlv.sound);
            ADD("id", mTlv.id);
            ADD("action", mTlv.action);
            ADD("set_value", mTlv.set_value);
        }
    };

    struct Path_SligLeftBound : public TlvObjectBaseAO<AO::Path_SligLeftBound>
    {
        CTOR_AO(Path_SligLeftBound, "SligLeftBound", AO::TlvTypes::eSligBoundLeft_57)
        {
            ADD("id", mTlv.field_18_slig_id);
            ADD("disabled_resources", mTlv.field_1A_disabled_resources.Raw().all);
        }
    };

    struct Path_SligRightBound : public TlvObjectBaseAO<AO::Path_SligRightBound>
    {
        CTOR_AO(Path_SligRightBound, "SligRightBound", AO::TlvTypes::eSligBoundRight_76)
        {
            ADD("id", mTlv.field_18_slig_id);
            ADD("disabled_resources", mTlv.field_1A_disabled_resources.Raw().all);
        }
    };

    struct Path_SligPersist : public TlvObjectBaseAO<AO::Path_SligPersist>
    {
        CTOR_AO(Path_SligPersist, "SligPersist", AO::TlvTypes::eSligPersist_77)
        {
            ADD("id", mTlv.field_18_slig_id);
            ADD("disabled_resources", mTlv.field_1A_disabled_resources.Raw().all);
        }
    };

    struct Path_SecurityOrb : public TlvObjectBaseAO<AO::Path_SecurityOrb>
    {
        CTOR_AO(Path_SecurityOrb, "SecurityOrb", AO::TlvTypes::SecurityOrb_29)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("disabled_resources", mTlv.field_1A_disable_resources);
        }
    };

    struct Path_FallingItem : public TlvObjectBaseAO<AO::Path_FallingItem>
    {
        CTOR_AO(Path_FallingItem, "FallingItem", AO::TlvTypes::FallingItem_15)
        {
            ADD("id", mTlv.field_18_id);
            ADD("scale", mTlv.field_1A_scale);
            ADD("delay_time", mTlv.field_1C_delay_time);
            ADD("number_of_items", mTlv.field_1E_number_of_items);
            ADD("reset_id", mTlv.field_20_reset_id);
        }
    };

    struct Path_Mine : public TlvObjectBaseAO<AO::Path_Mine>
    {
        CTOR_AO(Path_Mine, "Mine", AO::TlvTypes::Mine_46)
        {
            ADD("num_patterns", mTlv.field_18_num_patterns);
            ADD("pattern", mTlv.field_1A_pattern);
            ADD("scale", mTlv.field_1C_scale);
            ADD("disabled_resources", mTlv.field_1E_disabled_resources);
            ADD("persists_offscreen", mTlv.field_20_persists_offscreen);
        }
    };

    struct Path_Dove : public TlvObjectBaseAO<AO::Path_Dove>
    {
        CTOR_AO(Path_Dove, "Dove", AO::TlvTypes::Dove_12)
        {
            ADD("dove_count", mTlv.field_18_dove_count);
            ADD("pixel_perfect", mTlv.field_1A_pixel_perfect);
            ADD("scale", mTlv.field_1C_scale);
        }
    };

    struct Path_UXB : public TlvObjectBaseAO<AO::Path_UXB>
    {
        CTOR_AO(Path_UXB, "UXB", AO::TlvTypes::UXB_47)
        {
            ADD("num_patterns", mTlv.field_18_num_patterns);
            ADD("pattern", mTlv.field_1A_pattern);
            ADD("scale", mTlv.field_1C_scale);
            ADD("state", mTlv.field_1E_state);
        }
    };

    struct Path_HintFly : public TlvObjectBaseAO<AO::Path_HintFly>
    {
        CTOR_AO(Path_HintFly, "HintFly", AO::TlvTypes::HintFly_92)
        {
            ADD("message_id", mTlv.field_18_message_id);
        }
    };

    struct Path_Bat : public TlvObjectBaseAO<AO::Path_Bat>
    {
        CTOR_AO(Path_Bat, "Bat", AO::TlvTypes::Bat_49)
        {
            ADD("ticks_before_moving", mTlv.field_18_ticks_before_moving);
            ADD("speed", mTlv.field_1A_speed);
            ADD("scale", mTlv.field_1C_scale);
            ADD("attack_duration", mTlv.field_1E_attack_duration);
        }
    };

    struct Path_ShadowZone : public TlvObjectBaseAO<AO::Path_ShadowZone>
    {
        void AddTypes(TypesCollection& types) override
        {
            types.AddEnum<AO::ShadowZoneScale>("Enum_ShadowZoneScale",
                {
                    {AO::ShadowZoneScale::eBoth_0, "both"},
                    {AO::ShadowZoneScale::eHalf_1, "half"},
                    {AO::ShadowZoneScale::eFull_2, "full"},
                });
        }

        CTOR_AO(Path_ShadowZone, "ShadowZone", AO::TlvTypes::ShadowZone_7)
        {
            ADD("centre_w", mTlv.field_18_centre_w);
            ADD("centre_h", mTlv.field_1A_centre_h);
            ADD("r", mTlv.field_1C_r);
            ADD("g", mTlv.field_1E_g);
            ADD("b", mTlv.field_20_b);
            ADD("id", mTlv.field_22_id);
            ADD("scale", mTlv.field_24_scale);
        }
    };

    struct Path_BellHammer : public TlvObjectBaseAO<AO::Path_BellHammer>
    {
        CTOR_AO(Path_BellHammer, "BellHammer", AO::TlvTypes::BellHammer_27)
        {
            ADD("id", mTlv.field_18_id);
            ADD("action", mTlv.field_1A_action);
            ADD("scale", mTlv.field_1C_scale);
            ADD("direction", mTlv.field_1E_direction);
        }
    };

    struct Path_IdSplitter : public TlvObjectBaseAO<AO::Path_IdSplitter>
    {
        CTOR_AO(Path_IdSplitter, "IdSplitter", AO::TlvTypes::IdSplitter_94)
        {
            ADD("source_id", mTlv.field_18_source_id);
            ADD("delay", mTlv.field_1A_delay);
            ADD("id_1", mTlv.field_1C_id1);
            ADD("id_2", mTlv.field_1C_id2);
            ADD("id_3", mTlv.field_1C_id3);
            ADD("id_4", mTlv.field_1C_id4);
        }
    };

    struct Path_PullRingRope : public TlvObjectBaseAO<AO::Path_PullRingRope>
    {
        CTOR_AO(Path_PullRingRope, "PullRingRope", AO::TlvTypes::PullRingRope_18)
        {
            ADD("id", mTlv.field_18_id);
            ADD("action", mTlv.field_1A_action);
            ADD("rope_length", mTlv.field_1C_rope_length);
            ADD("scale", mTlv.field_1E_scale);
            ADD("on_sound", mTlv.field_20_on_sound);
            ADD("off_sound", mTlv.field_22_off_sound);
            ADD("sound_direction", mTlv.field_24_sound_direction);
        }
    };

    struct Path_MusicTrigger : public TlvObjectBaseAO<AO::Path_MusicTrigger>
    {
        CTOR_AO(Path_MusicTrigger, "MusicTrigger", AO::TlvTypes::MusicTrigger_105)
        {
            ADD("type", mTlv.field_18_type);
            ADD("enabled_by", mTlv.field_1A_enabled_by);
            ADD("id", mTlv.field_1C_id);
            ADD("timer", mTlv.field_1E_timer);
        }
    };

    struct Path_ElumPathTrans : public TlvObjectBaseAO<AO::Path_ElumPathTrans>
    {
        CTOR_AO(Path_ElumPathTrans, "ElumPathTrans", AO::TlvTypes::ElumPathTrans_99)
        {
            ADD("level", mTlv.field_18_level);
            ADD("path", mTlv.field_1A_path);
            ADD("camera", mTlv.field_1C_camera);
        }
    };

    struct Path_ElumStart : public TlvObjectBaseAO<AO::Path_ElumStart>
    {
        CTOR_AO(Path_ElumStart, "ElumStart", AO::TlvTypes::ElumStart_38)
        {
            // No fields
        }
    };

    struct Path_ElumWall : public TlvObjectBaseAO<AO::Path_ElumWall>
    {
        CTOR_AO(Path_ElumWall, "ElumWall", AO::TlvTypes::ElumWall_40)
        {
            // No fields
        }
    };

    struct Path_LiftPoint : public TlvObjectBaseAO<AO::Path_LiftPoint>
    {
        CTOR_AO(Path_LiftPoint, "LiftPoint", AO::TlvTypes::LiftPoint_8)
        {
            ADD("id", mTlv.field_18_id);
            ADD("is_start_point", mTlv.field_1A_bstart_point);
            ADD("lift_type", mTlv.field_1C_lift_type);
            ADD("lift_point_stop_type", mTlv.field_1E_lift_point_stop_type);
            ADD("scale", mTlv.field_20_scale);
            ADD("ignore_lift_mover", mTlv.field_22_bIgnore_lift_mover);
        }
    };

    struct Path_MovingBomb : public TlvObjectBaseAO<AO::Path_MovingBomb>
    {
        CTOR_AO(Path_MovingBomb, "MovingBomb", AO::TlvTypes::MovingBomb_86)
        {
            ADD("speed", mTlv.field_18_speed);
            ADD("id", mTlv.field_1A_id);
            ADD("start_type_triggered_by_alarm", mTlv.field_1C_bStart_type_triggered_by_alarm);
            ADD("scale", mTlv.field_1E_scale);
            ADD("max_rise", mTlv.field_20_max_rise);
            ADD("disabled_resources", mTlv.field_22_disabled_resources);
            ADD("start_speed", mTlv.field_24_start_speed);
            ADD("persist_offscreen", mTlv.field_26_persist_offscreen);
        }
    };

    struct Path_MovingBombStopper : public TlvObjectBaseAO<AO::Path_MovingBombStopper>
    {
        CTOR_AO(Path_MovingBombStopper, "MovingBombStopper", AO::TlvTypes::MovingBombStopper_87)
        {
            ADD("min_delay", mTlv.field_18_min_delay);
            ADD("max_delay", mTlv.field_1A_max_delay);
        }
    };

    struct Path_RingMudokon : public TlvObjectBaseAO<AO::Path_RingMudokon>
    {
        CTOR_AO(Path_RingMudokon, "RingMudokon", AO::TlvTypes::RingMudokon_50)
        {
            ADD("facing", mTlv.field_18_facing);
            ADD("abe_must_be_same_direction", mTlv.field_1A_abe_must_be_same_direction);
            ADD("scale", mTlv.field_1C_scale);
            ADD("silent", mTlv.field_1E_silent);
            ADD("code1", mTlv.field_20_code1);
            ADD("code2", mTlv.field_22_code2);
            ADD("action", mTlv.field_24_action);
            ADD("ring_timeout", mTlv.field_26_ring_timeout);
            ADD("instant_powerup", mTlv.field_28_instant_powerup);
        }
    };

    struct Path_RingCancel : public TlvObjectBaseAO<AO::Path_RingCancel> // TODO: correct size is 24 not 28
    {
        CTOR_AO(Path_RingCancel, "RingCancel", AO::TlvTypes::RingCancel_109)
        {
            ADD("shrykull_remove", mTlv.field_18_bShrykull_remove);
        }
    };

    struct Path_MeatSaw : public TlvObjectBaseAO<AO::Path_MeatSaw>
    {
        CTOR_AO(Path_MeatSaw, "MeatSaw", AO::TlvTypes::MeatSaw_88)
        {
            ADD("scale", mTlv.field_18_scale_background);
            ADD("min_time_off1", mTlv.field_1A_min_time_off1);
            ADD("max_time_off1", mTlv.field_1C_max_time_off1);
            ADD("max_rise_time", mTlv.field_1E_max_rise_time);
            ADD("id", mTlv.field_20_id);
            ADD("type", mTlv.field_22_type);
            ADD("speed", mTlv.field_24_speed);
            ADD("start_state", mTlv.field_26_start_state);
            ADD("off_speed", mTlv.field_28_off_speed);
            ADD("min_time_off2", mTlv.field_2A_min_time_off2);
            ADD("max_time_off2", mTlv.field_2C_max_time_off2);
            ADD("initial_position", mTlv.field_2E_inital_position);
        }
    };

    struct Path_LCDScreen : public TlvObjectBaseAO<AO::Path_LCDScreen>
    {
        CTOR_AO(Path_LCDScreen, "LCDScreen", AO::TlvTypes::LCDScreen_98)
        {
            ADD("message_1_id", mTlv.field_18_message_1_id);
            ADD("message_rand_min", mTlv.field_1A_message_rand_min);
            ADD("message_rand_max", mTlv.field_1C_message_rand_max);
        }
    };

    struct Path_InvisibleSwitch : public TlvObjectBaseAO<AO::Path_InvisibleSwitch>
    {
        CTOR_AO(Path_InvisibleSwitch, "InvisibleSwitch", AO::TlvTypes::InvisibleSwitch_81)
        {
            ADD("id", mTlv.field_18_id);
            ADD("action", mTlv.field_1A_action);
            ADD("delay", mTlv.field_1C_delay);
            ADD("set_off_alarm", mTlv.field_1E_set_off_alarm);
            ADD("scale", mTlv.field_20_scale);
        }
    };

    struct Path_TrapDoor : public TlvObjectBaseAO<AO::Path_TrapDoor>
    {
        CTOR_AO(Path_TrapDoor, "TrapDoor", AO::TlvTypes::TrapDoor_55)
        {
            ADD("id", mTlv.field_18_id);
            ADD("start_state", mTlv.field_1A_start_state);
            ADD("self_closing", mTlv.field_1C_self_closing);
            ADD("scale", mTlv.field_1E_scale);
            ADD("dest_level", mTlv.field_20_dest_level);
            ADD("direction", mTlv.field_22_direction);
            ADD("anim_offset", mTlv.field_24_anim_offset);
        }
    };

    struct Path_BirdPortal : public TlvObjectBaseAO<AO::Path_BirdPortal>
    {
        void AddTypes(TypesCollection& types) override
        {
            types.AddEnum<AO::PortalSide>("Enum_PortalSide",
                {
                    {AO::PortalSide::eRight_0, "right"},
                    {AO::PortalSide::eLeft_1, "left"},
                });

            types.AddEnum<AO::PortalType>("Enum_PortalType",
                {
                    {AO::PortalType::eAbe_0, "abe"},
                    {AO::PortalType::eWorker_1, "worker"},
                    {AO::PortalType::eShrykull_2, "shrykull"},
                    {AO::PortalType::eMudTeleport_3, "mud_teleport"},
                });
        }

        CTOR_AO(Path_BirdPortal, "BirdPortal", AO::TlvTypes::BirdPortal_52)
        {
            ADD("side", mTlv.field_18_side);
            ADD("dest_level", mTlv.field_1A_dest_level);
            ADD("dest_path", mTlv.field_1C_dest_path);
            ADD("dest_camera", mTlv.field_1E_dest_camera);
            ADD("scale", mTlv.field_20_scale);
            ADD("movie_id", mTlv.field_22_movie_id);
            ADD("portal_type", mTlv.field_24_portal_type);
            ADD("num_muds_for_shrykull", mTlv.field_26_num_muds_for_shrykul);
        }
    };

    struct Path_BoomMachine : public TlvObjectBaseAO<AO::Path_BoomMachine>
    {
        CTOR_AO(Path_BoomMachine, "BoomMachine", AO::TlvTypes::BoomMachine_97)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("nozzle_side", mTlv.field_1A_nozzle_side);
            ADD("disabled_resources", mTlv.field_1C_disabled_resources);
            ADD("number_of_grenades", mTlv.field_1E_number_of_grenades);
        }
    };

    struct Path_Mudokon : public TlvObjectBaseAO<AO::Path_Mudokon>
    {
        CTOR_AO(Path_Mudokon, "Mudokon", AO::TlvTypes::Mudokon_82)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("job", mTlv.field_1A_job);
            ADD("direction", mTlv.field_1C_direction);
            ADD("voice_adjust", mTlv.field_1E_voice_adjust);
            ADD("rescue_id", mTlv.field_20_rescue_id);
            ADD("deaf", mTlv.field_22_deaf);
            ADD("disabled_resources", mTlv.field_24_disabled_resources);
            ADD("persist", mTlv.field_26_persist);
        }
    };

    struct Path_BirdPortalExit : public TlvObjectBaseAO<AO::Path_BirdPortalExit>
    {
        CTOR_AO(Path_BirdPortalExit, "BirdPortalExit", AO::TlvTypes::BirdPortalExit_53)
        {
            ADD("side", mTlv.field_18_side);
            ADD("scale", mTlv.field_1A_scale);
        }
    };

    struct Path_Slog : public TlvObjectBaseAO<AO::Path_Slog>
    {
        CTOR_AO(Path_Slog, "Slog", AO::TlvTypes::Slog_25)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("direction", mTlv.field_1A_direction);
            ADD("wakeup_anger", mTlv.field_1C_wakeup_anger);
            ADD("bark_anger", mTlv.field_1E_bark_anger);
            ADD("sleeps", mTlv.field_20_sleeps);
            ADD("chase_anger", mTlv.field_22_chase_anger);
            ADD("jump_attack_delay", mTlv.field_24_jump_attack_delay);
            ADD("disabled_resources", mTlv.field_26_disabled_resources);
            ADD("anger_trigger_id", mTlv.field_28_anger_trigger_id);
        }
    };

    struct Path_ChimeLock : public TlvObjectBaseAO<AO::Path_ChimeLock>
    {
        CTOR_AO(Path_ChimeLock, "ChimeLock", AO::TlvTypes::ChimeLock_69)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("solve_id", mTlv.field_1A_solve_id);
            ADD("code1", mTlv.field_1C_code1);
            ADD("code2", mTlv.field_1E_code2);
            ADD("id", mTlv.field_20_id);
        }
    };

    struct Path_FlintLockFire : public TlvObjectBaseAO<AO::Path_FlintLockFire>
    {
        CTOR_AO(Path_FlintLockFire, "FlintLockFire", AO::TlvTypes::FlintLockFire_73)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("id", mTlv.field_1A_id);
        }
    };

    struct Path_LiftMover : public TlvObjectBaseAO<AO::Path_LiftMover>
    {
        CTOR_AO(Path_LiftMover, "LiftMover", AO::TlvTypes::LiftMover_68)
        {
            ADD("switch_id", mTlv.field_18_switch_id);
            ADD("lift_id", mTlv.field_1A_lift_id);
            ADD("direction", mTlv.field_1C_direction);
        }
    };

    struct Path_Scrab : public TlvObjectBaseAO<AO::Path_Scrab>
    {
        CTOR_AO(Path_Scrab, "Scrab", AO::TlvTypes::Scrab_72)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("attack_delay", mTlv.field_1A_attack_delay);
            ADD("patrol_type", mTlv.field_1C_patrol_type);
            ADD("left_min_delay", mTlv.field_1E_left_min_delay);
            ADD("left_max_delay", mTlv.field_20_left_max_delay);
            ADD("right_min_delay", mTlv.field_22_right_min_delay);
            ADD("right_max_delay", mTlv.field_24_right_max_delay);
            ADD("attack_duration", mTlv.field_26_attack_duration);
            ADD("disable_resources", mTlv.field_28_disable_resources);
            ADD("roar_randomly", mTlv.field_2A_roar_randomly);
        }
    };

    struct Path_SlogSpawner : public TlvObjectBaseAO<AO::Path_SlogSpawner>
    {
        CTOR_AO(Path_SlogSpawner, "SlogSpawner", AO::TlvTypes::SlogSpawner_107)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("num_slogs", mTlv.field_1A_num_slogs);
            ADD("num_at_a_time", mTlv.field_1C_num_at_a_time);
            ADD("direction", mTlv.field_1E_direction);
            ADD("ticks_between_slogs", mTlv.field_20_ticks_between_slogs);
            ADD("start_id", mTlv.field_22_start_id);
        }
    };

    struct Path_RockSack : public TlvObjectBaseAO<AO::Path_RockSack>
    {
        CTOR_AO(Path_RockSack, "RockSack", AO::TlvTypes::RockSack_13)
        {
            ADD("side", mTlv.field_18_side);
            ADD("x_vel", mTlv.field_1A_x_vel);
            ADD("y_vel", mTlv.field_1C_y_vel);
            ADD("scale", mTlv.field_1E_scale);
            ADD("num_rocks", mTlv.field_20_num_rocks);
        }
    };

    struct Path_SlogHut : public TlvObjectBaseAO<AO::Path_SlogHut>
    {
        CTOR_AO(Path_SlogHut, "SlogHut", AO::TlvTypes::SlogHut_111)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("switch_id", mTlv.field_1A_switch_id);
            ADD("z_delay", mTlv.field_1C_z_delay);
        }
    };

    struct Path_SecurityClaw : public TlvObjectBaseAO<AO::Path_SecurityClaw>
    {
        CTOR_AO(Path_SecurityClaw, "SecurityClaw", AO::TlvTypes::SecurityClaw_61)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("alarm_id", mTlv.field_1A_alarm_id);
            ADD("alarm_time", mTlv.field_1C_alarm_time);
            ADD("disabled_resources", mTlv.field_1E_disabled_resources);
        }
    };

    struct Path_SecurityDoor : public TlvObjectBaseAO<AO::Path_SecurityDoor>
    {
        CTOR_AO(Path_SecurityDoor, "SecurityDoor", AO::TlvTypes::SecurityDoor_95)
        {
            ADD("scale", mTlv.field_18_scale);
            ADD("id", mTlv.field_1A_id);
            ADD("code_1", mTlv.field_1C_code_1);
            ADD("code_2", mTlv.field_1E_code2);
            ADD("xpos", mTlv.field_20_xpos);
            ADD("ypos", mTlv.field_22_ypos);
        }
    };

    struct Path_TimedMine : public TlvObjectBaseAO<AO::Path_TimedMine>
    {
        CTOR_AO(Path_TimedMine, "TimedMine", AO::TlvTypes::TimedMine_22)
        {
            ADD("id", mTlv.field_18_id);
            ADD("state", mTlv.field_1A_state);
            ADD("scale", mTlv.field_1C_scale);
            ADD("ticks_before_explode", mTlv.field_1E_ticks_before_explode);
            ADD("disable_resources", mTlv.field_20_disable_resources);
        }
    };
}