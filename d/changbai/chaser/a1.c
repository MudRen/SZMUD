// Code of ShenZhou
// /d/changbai/npc/fang.c ������
// by ALN  1/98

#include <ansi.h>
#include <room.h>
#include <command.h>

inherit NPC;

int auto_perform();

string* myskills = ({
        "huashan-jianfa",
        "damo-jian", 
        "huifeng-jian",
        "duanjia-jian",
        "jinshe-jianfa",
        "tangshi-jian",
        "wugou-jianfa",
        "yuxiao-jian",
});

string temp;

void create()
{
        set_name("������", ({ "fang dongbai", "fang" }));
        set("nickname", "�˱���");
        set("title", "ؤ��Ŵ�����");
        set("long",
"��������ݳ����������ƣ���ü�������ƺ��ղŸ���ʹŹ��һ�١�\n"
"��ԭ����ؤ���Ĵ���֮�ף�����֮��������������\n"
"ֻ����������죬���������߰����ֱ�һ�㣬��˵��ˡ��˱��񽣡������š�\n");
        set("gender", "����");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 3500);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 1400000);
        set("score", 5000);

        set_temp("apply/armor", 100);
        set_temp("apply/speed", 120);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 100);

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("strike", 180);
        set_skill("huntian-qigong", 180);
        set_skill("xianglong-zhang", 180);
        set_skill("xiaoyaoyou", 200);

        for( int i = 0; i < sizeof(myskills); i++ ) {
                set_skill(myskills[i], 180);
        }
        temp = myskills[random(sizeof(myskills))];

        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", temp);
        map_skill("sword", temp);
        map_skill("strike", "xianglong-zhang");

        prepare_skill("strike", "xianglong-zhang");

        create_family("ؤ��", 21, "�Ŵ�����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        setup();

        call_out("chaser_check", 1);

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int auto_perform()
{
        object me = this_object();
        object weapon = me->query_temp("weapon");

        if( objectp(weapon) ) {
                if( weapon->query("skill_type") == "sword" ) {
                        temp = myskills[random(sizeof(myskills))];
                        map_skill("sword", temp);
                        map_skill("parry", temp);
                        me->reset_action();
                }
                return 1;
        }

        if( me->query_skill_mapped("parry") != "xianglong-zhang" ) {
                map_skill("parry", "xianglong-zhang");
                me->reset_action();
        }

        if( !random(3) )
                return  perform_action("strike.leiting");

        return 1;
}

#include "/d/changbai/chaser/chaser.h";





