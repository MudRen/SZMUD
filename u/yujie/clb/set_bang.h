// Code of ShenZhou
// /d/huanghe/doc/set_bang.h
// by aln 2 / 98

#ifndef BANGZHONG
#define BANGZHONG  "/d/huanghe/npc/bangzhong"
#endif

void set_bang(object owner)
{
        object ob, *obj = ({}), room = environment(owner);

        if( !room ) return;

        ob = new(BANGZHONG);
        set_follower(ob, owner);
        ob->move(room);
        obj += ({ob});

        ob = new(BANGZHONG);
        set_follower(ob, owner);
        ob->move(room);
        obj += ({ob});

        owner->set("follower", obj);

        message("vision",
                ob->name() + "���˹�����\n",
                room, ({ob}));
        message_vision("$N����$n���˸�Ҿ�������������˼������ˡ�\n", ob, owner);
        message_vision("$N���˵�ͷ�����������������ˡ�\n", owner);
}


void set_follower(object obnpc, object owner)
{
        string fam, name;
        string  bc_skills, *weapons, *bc_enskills ,weapon_skills,sp_skills;
        int i, exp, level;

        obnpc->set("owner", owner);
        obnpc->set_leader(owner);

        fam = (string)owner->query("fam");
        obnpc->set("title", fam);

        exp = (int)owner->query("combat_exp") / 2;
        obnpc->set("combat_exp", exp);
        level = ceil( pow( to_float(exp) * 10.0, 0.333333) ) * 4 / 5;

           obnpc->set("max_qi",    level * 8 + 100);
           obnpc->set("max_jing",  level * 5 + 100);
           obnpc->set("qi",    level * 8 + 100);
           obnpc->set("jing",  level * 5 + 100);
           obnpc->set("max_neili", level * 6 + 200);
           obnpc->set("neili",     level * 6 + 200);
           obnpc->reincarnate();
           obnpc->clear_condition();
           

           obnpc->set_skill("dodge", level);
           obnpc->set_skill("force", level);
           obnpc->set_skill("parry", level);

           bc_skills = keys(unarmed_skills)[random(sizeof(keys(unarmed_skills)))];
           bc_enskills=unarmed_skills[bc_skills];
           sp_skills=bc_enskills[random(sizeof(bc_enskills))];
           obnpc->set_skill(bc_skills, level);
           obnpc->set_skill(sp_skills,level);
           obnpc->map_skill(bc_skills,sp_skills);
           obnpc->prepare_skill(bc_skills,sp_skills);
           obnpc->map_skill("parry", sp_skills);

        
           i = random(sizeof(info_weapon));
           obnpc->set_skill(info_weapon[i]["type"], level);
           weapon_skills=info_weapon[i]["skills"][random(sizeof(info_weapon[i]["skills"]))];
           obnpc->set_skill(weapon_skills,level);
           obnpc->map_skill(info_weapon[i]["type"],weapon_skills);

           level /= 3;
           obnpc->set_temp("apply/defense", level);
           obnpc->set_temp("apply/armor",   level);
           obnpc->set_temp("apply/damage",  level);
           obnpc->set_temp("apply/attack",  level);

           if( !random(2) ) {
                weapons = info_weapon[i]["weapons"];
                obnpc->carry_object(weapons[random(sizeof(weapons))])->wield();
           }

        obnpc->set("inquiry/" + fam, fam + "���𽭺���ָ�տɴ�������");
        name = (string)owner->query("name");
        obnpc->set("inquiry/" + "����", "�Ҷ�����" + name[0..01] + "�����ľ���֮���������Ͻ�ˮ���಻����");
        obnpc->set("inquiry/" + name, "�⼸��������˵����");
        obnpc->set("inquiry/" + name[0..01] + "����", "�Ҷ�����" + name[0..01] + "����ľ���֮�飬�������Ͻ�ˮ���಻����");
}



