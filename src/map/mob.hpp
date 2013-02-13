#ifndef MOB_HPP
#define MOB_HPP

#include "mob.t.hpp"

#include "../common/mmo.hpp"
#include "../common/timer.t.hpp"
#include "../common/random.t.hpp"

#include "clif.t.hpp"
#include "map.hpp"
#include "skill.t.hpp"

struct mob_skill
{
    MobSkillState state;
    SkillID skill_id;
    short skill_lv;
    short permillage;
    interval_t casttime, delay;
    short cancel;
    MobSkillCondition cond1;
    int cond2i;
    MobSkillTarget target;
    int val[5];
    short emotion;
};

struct mob_db
{
    char name[24], jname[24];
    int lv;
    int max_hp, max_sp;
    int base_exp, job_exp;
    int atk1, atk2;
    int def, mdef;
    earray<int, ATTR, ATTR::COUNT> attrs;
    int range, range2, range3;
    // always 1
    int size;
    Race race;
    LevelElement element;
    MobMode mode;
    int speed, adelay, amotion, dmotion;
    int mutations_nr, mutation_power;
    struct
    {
        int nameid;
        random_::Fixed<int, 10000> p;
    } dropitem[8];
    int sex;
    short hair, hair_color, weapon, shield, head_top, head_mid, head_buttom, option, clothes_color; // [Valaris]
    int equip;                 // [Valaris]
    int maxskill;
    struct mob_skill skill[MAX_MOBSKILL];
};
extern struct mob_db mob_db[];

int mobdb_searchname(const char *str);
int mobdb_checkid(const int id);
int mob_once_spawn(struct map_session_data *sd,
        const char *mapname, int x, int y,
        const char *mobname, int class_, int amount, const char *event);
int mob_once_spawn_area(struct map_session_data *sd,
        const char *mapname, int x0, int y0, int x1, int y1,
        const char *mobname, int class_, int amount, const char *event);

int mob_target(struct mob_data *md, struct block_list *bl, int dist);
int mob_stop_walking(struct mob_data *md, int type);
int mob_stopattack(struct mob_data *);
int mob_spawn(int);
int mob_damage(struct block_list *, struct mob_data *, int, int);
int mob_heal(struct mob_data *, int);
int mob_get_sex(int);
short mob_get_hair(int);
short mob_get_hair_color(int);
short mob_get_weapon(int);
short mob_get_shield(int);
short mob_get_head_top(int);
short mob_get_head_mid(int);
short mob_get_head_buttom(int);
short mob_get_clothes_color(int);  //player mob dye [Valaris]
int mob_get_equip(int);       // mob equip [Valaris]
int do_init_mob(void);

int mob_delete(struct mob_data *md);
int mob_catch_delete(struct mob_data *md, BeingRemoveWhy type);
void mob_timer_delete(TimerData *, tick_t, int);

int mob_deleteslave(struct mob_data *md);

int mob_counttargeted(struct mob_data *md, struct block_list *src,
        ATK target_lv);

int mob_warp(struct mob_data *md, int m, int x, int y, BeingRemoveWhy type);

int mobskill_use(struct mob_data *md, tick_t tick, MobSkillCondition event);
int mobskill_event(struct mob_data *md, BF flag);
void mobskill_castend_id(TimerData *tid, tick_t tick, int id);
void mobskill_castend_pos(TimerData *tid, tick_t tick, int id);
int mob_summonslave(struct mob_data *md2, int *value, int amount, int flag);

void mob_reload(void);

#endif // MOB_HPP
