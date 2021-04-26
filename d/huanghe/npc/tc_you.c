// Code of ShenZhou
// you.c

inherit NPC;

int ask_join();

void create()
{
        set_name("�ȵ�ʤ", ({ "you deshen", "you" }));
        set("title", "��������");
        set("long",
"�����ǳ���Զ������������ȵ�ʤ��һλ��ʮ����ı��δ󺺣�\n"
"�ֳ�һ�����λεĸֲ棬�ƺ�������ʲô�����⡣\n");
        set("gender", "����");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 28);
        set("int", 20);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 800);
        set("max_jing", 500);
        set("max_neili", 700);
        set("neili", 700);
        set("jiali", 30);
        set("combat_exp", 150000);
        set("score", 7000);

        set_temp("apply/armor", 40);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("cuff",  100);
        set_skill("pike",  100);

        set_skill("ding-force", 100);
        set_skill("wuxingbu", 100);
        set_skill("wuxing-quan", 100);
        set_skill("liuhe-qiang", 100);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "liuhe-qiang");
        map_skill("pike", "liuhe-qiang");

        prepare_skill("cuff", "wuxing-quan");

        set("inquiry", ([
                "�����" : "�����������лƺ��������첻�£��ز��£����ʵ��϶������������ʡ�",
                "�ȵ�ʤ" : "������ɽ���������š���Ωһ���ˣ��淨������˫�����ʶһ����",
                "���Ʒ���ʹ��" : "���ǧ�򲻿������Ʒ���ʹ�ߵ�֪���������İ�ַ����",
                "���͵�" : "���͵����Ʒ���ʹ�����뽭������������ﻹ����ʱ��һ�ܰѡ�����",
                "�����" : "���ϵ��ڱװ���µ������Ҷ���ʮ�����ء�",
                "������" : "�ͷ���������ͷ�����Գ�Ӣ�ۺú�������çײ����������һ���Ǻ����ĵġ�",
                "����" : "�Ҿ���������������ʲ����ʵģ�",
        ]));

        setup();

        carry_object("/clone/weapon/sangucha")->wield();
}
