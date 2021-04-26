// Code of ShenZhou
// /d/changbai/npc/a3.c ����
// by ALN  1/98

#include <ansi.h>
#include <room.h>
#include <command.h>

inherit NPC;

void create()
{
        set_name("����", ({ "a san", "san" }));
        set("long",
"���˾�׳��ʵ���������������ϡ����ϡ��֮�У����ǿɼ������⴦��\n"
"�����̸��ᣬ�ƺ������Ǿ������͵�Ҫ��ը������\n"
"��������пź��룬����������һ�Գ�ë��\n");
        set("gender", "����");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 500000);
        set("score", 2000);

        set_temp("apply/armor", 80);
        set_temp("apply/defense", 60);
        set_temp("apply/damage", 30);

        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("cuff", 120);
        set_skill("finger", 120);

        set_skill("hunyuan-yiqi", 120);
        set_skill("shaolin-shenfa", 120);
        set_skill("jingang-quan", 120);
        set_skill("nianhua-zhi", 120);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "jingang-quan");
        map_skill("cuff", "jingang-quan");
        map_skill("finger", "nianhua-zhi");

        prepare_skill("cuff", "jingang-quan");
        prepare_skill("finger", "nianhua-zhi");

        setup();

        call_out("chaser_check", 1);

        carry_object("/clone/misc/cloth")->wear();
}

#include "/d/changbai/chaser/chaser.h";
