// Code of ShenZhou
// /d/changbai/npc/a2.c ����
// by ALN  1/98

#include <ansi.h>
#include <room.h>
#include <command.h>

inherit NPC;

void create()
{
        set_name("����", ({ "a er", "er" }));
        set("long",
"���˾��ɿ��ݣ�����԰���\n"
"��ͷ���Ļ����͵أ�ͺ�ò�ʣ���ͷ��������̫��Ѩ���˽�ȥ�����ݰ�硣\n");
        set("nickname", "ͺͷ");
        set("gender", "����");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 2000);
        set("max_jing", 1200);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 80);
        set("combat_exp", 1000000);
        set("score", 3500);

        set_temp("apply/armor", 100);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 80);

        set_skill("force", 150);
        set_skill("dodge", 160);
        set_skill("parry", 150);
        set_skill("strike", 150);
        set_skill("hand", 150);

        set_skill("hunyuan-yiqi", 150);
        set_skill("shaolin-shenfa", 160);
        set_skill("sanhua-zhang", 150);
        set_skill("fengyun-shou", 150);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "sanhua-zhang");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "fengyun-shou");

        prepare_skill("strike", "sanhua-zhang");
        prepare_skill("hand", "fengyun-shou");

        setup();

        call_out("chaser_check", 1);

        carry_object("/clone/misc/cloth")->wear();
}

#include "/d/changbai/chaser/chaser.h";
