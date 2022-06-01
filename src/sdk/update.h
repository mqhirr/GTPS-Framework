#ifndef __SDK__UPDATE_H__
#define __SDK__UPDATE_H__
#include <stdint.h>

struct gameupdatepacket_t
{
    uint8_t m_type = 0;
    union
    {
        uint8_t m_obj_type = 0;
        uint8_t m_punch_id;
        uint8_t m_npc_type;
    };
    union
    {
        uint8_t m_count1 = 0;
        uint8_t m_jump_count;
        uint8_t m_build_range;
        uint8_t m_npc_id;
        uint8_t m_lost_item_count;
    };
    union
    {
        uint8_t m_count2 = 0;
        uint8_t m_animation_type;
        uint8_t m_punch_range;
        uint8_t m_npc_action;
        uint8_t m_particle_id;
        uint8_t m_gained_item_count;
        uint8_t m_dice_result;
        uint8_t m_fruit_count;
    };
    union
    {
        int32_t m_net_id = 0;
        int32_t m_owner_id;
        int32_t m_effect_flags_check;
        int32_t m_object_change_type;
        int32_t m_particle_emitter_id;
    };
    union
    {
        int32_t m_item = 0;
        int32_t m_ping_hash;
        int32_t m_item_net_id;
        int32_t m_pupil_color;
        int32_t m_target_net_id;
        int32_t m_tiles_length;
    };
    int32_t m_flags = 0;
    union
    {
        float m_float_var = 0;
        float m_water_speed;
        float m_obj_alt_count;
    };
    union
    {
        int32_t m_int_data = 0;
        int32_t m_ping_item;
        int32_t m_elapsed_ms;
        int32_t m_delay;
        int32_t m_tile_damage;
        int32_t m_item_id;
        int32_t m_item_speed;
        int32_t m_effect_flags;
        int32_t m_object_id;
        int32_t m_hash;
        int32_t m_verify_pos;
        int32_t m_client_hack_type;
    };
    union
    {
        float m_vec_x = 0;
        float m_pos_x;
        float m_accel;
        float m_punch_range_in;
    };
    union
    {
        float m_vec_y = 0;
        float m_pos_y;
        float m_build_range_in;
        float m_punch_strength;
    };
    union
    {
        float m_vec2_x = 0;
        float m_dest_x;
        float m_gravity_in;
        float m_speed_out;
        float m_velocity_x;
        float m_particle_variable;
        float m_pos2_x;
        int m_hack_type;
    };
    union
    {
        float m_vec2_y = 0;
        float m_dest_y;
        float m_speed_in;
        float m_gravity_out;
        float m_velocity_y;
        float m_particle_alt_id;
        float m_pos2_y;
        int m_hack_type2;
    };
    union
    {
        float m_particle_rotation = 0;
        float m_npc_variable;
    };
    union
    {
        uint32_t m_int_x = 0;
        uint32_t m_tile_pos_x;
        uint32_t m_item_id_alt;
        uint32_t m_hair_color;
    };
    union
    {
        uint32_t m_int_y = 0;
        uint32_t m_tile_pos_y;
        uint32_t m_item_count;
        uint32_t m_eyecolor;
        uint32_t m_npc_speed;
        uint32_t m_particle_size_alt;
    };
    uint32_t m_data_size = 0;
    uint8_t m_data = 0;
};
#endif // __SDK__UPDATE_H__