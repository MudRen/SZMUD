//Cracked by Roath
// dujie.c

#include <ansi.h>

inherit NPC;
#include "/kungfu/class/shaolin/auto_perform.h";
void create()
{
        set_name("�ɽ�", ({ "du jie", "jie" }) );
        set("title", "���ֳ���");
        set("gender", "����");
        set("age", 90);
        set("long",
                "����һ��������ݣ��ݹ��㶡����ɮ������ɫ�Ұף���һ��ֽһ����\n");

        set("attitude", "peaceful");
        set("combat_exp", 1500000);
        set("score", 200000);

        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);

        set("max_qi", 3000);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);

        create_family("������", 35, "����");
        set("class", "bonze");
        assign_apprentice("����", 0);

        set_skill("force", 150);
        set_skill("cuff", 180);
        set_skill("whip", 180);
        set_skill("parry", 160);
        set_skill("dodge", 170);

        set_skill("buddhism", 150);
        set_skill("hunyuan-yiqi", 180);
        set_skill("jingang-quan", 180);
        set_skill("riyue-bian", 180);
        set_skill("shaolin-shenfa", 160);

        map_skill("force", "hunyuan-yiqi");
        map_skill("cuff",  "jingang-quan");
        map_skill("whip",  "riyue-bian");
        map_skill("parry", "riyue-bian");
        map_skill("dodge", "shaolin-shenfa");

        prepare_skill("cuff", "jingang-quan");

        set("chat_chance", 80);
        set("chat_msg", ({
                (: auto_perform :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );


        setup();

	carry_object("/clone/weapon/bian")->wield();
}

#include "/d/xiakedao/npc/du.h"

