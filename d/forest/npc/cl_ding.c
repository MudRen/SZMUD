// Code of ShenZhou
// /d/huanghe/changle/npc/dingbusi.c
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("������", ({ "ding busi", "ding" }));
        set("nickname", "һ�ղ�����");
        set("long", 
                "�����뷢�Ȼ���Ǹ���Ŀ�������ͷ�������������һ��\n"
                "�������ݵ��׺�֮�⡣���������һ�������õľŽڱޡ�\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 1800);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 60);
        set("combat_exp", 650000);
        set("score", 30000);

        set_temp("apply/attack", 40);
        set_temp("apply/damage", 40);
        set_temp("apply/armor",  40);

        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("cuff",  150);
        set_skill("whip",  150);

        set_skill("ding-force",    150);
        set_skill("liuxing-bu",    150);
        set_skill("yanqing-quan",  150);
        set_skill("canglang-bian", 150);
 
        map_skill("force",    "ding-force");
        map_skill("dodge",  "yanqing-quan");
        map_skill("cuff",   "yanqing-quan");
        map_skill("parry", "canglang-bian");
        map_skill("whip",  "canglang-bian");

        set("chat_chance", 8);
        set("chat_msg", ({
                (: random_move :)
        }) );

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changbian")->wield();
 //     carry_object("/clone/weapon/jiujiebian")->wield();
}

