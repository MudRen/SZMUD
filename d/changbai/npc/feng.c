// Code of ShenZhou
// /d/changbai/npc/feng.c

inherit NPC;

void create()
{
        set_name("������", ({ "feng xifan", "feng" }));
        set("nickname", "һ����Ѫ");
        set("long",
"����ò���������з��ڣ�������Ʋ��β�롣\n"
"һ��û����ɵ�ģ�������Ƹ��첡��ģ����\n"
"��żȻһ˫�۾������ˣ�ȴ����⾼����\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);

        set("jiali", 60);

        set("combat_exp", 800000);

        set_temp("apply/armor", 40);

        set_skill("force", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("sword", 160);
        set_skill("strike", 160);
        set_skill("ding-force", 160);
        set_skill("wugou-jianfa", 160);
        set_skill("wuyu-zhangfa", 160);
        set_skill("tiyunzong", 160);

        map_skill("strike", "wuyu-zhangfa");
        map_skill("force", "ding-force");
        map_skill("parry", "wugou-jianfa");
        map_skill("sword", "wugou-jianfa");
        map_skill("dodge", "tiyunzong");

        prepare_skill("strike", "wuyu-zhangfa");

        setup();

        carry_object("/clone/weapon/qinggang-jian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


