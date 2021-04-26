// Code of ShenZhou
// /d/huanghe/npc/tc_hu.c

inherit NPC;

int ask_job();

void create()
{
        set_name("�����", ({ "hu dage", "hu" }));
        set("title", "����������");
        set("long",
"����һλ��ʮ����ı��δ󺺡�\n");
        set("gender", "����");
        set("age", 42);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 800);
        set("max_jing", 500);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 20);
        set("combat_exp", 80000);
        set("score", 5000);

        set_temp("apply/armor", 30);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("cuff",  80);
        set_skill("pike",  90);

        set_skill("ding-force", 80);
        set_skill("wuxingbu", 80);
        set_skill("wuxing-quan", 80);
        set_skill("liuhe-qiang", 90);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "liuhe-qiang");
        map_skill("pike", "liuhe-qiang");

        prepare_skill("cuff", "wuxing-quan");

        set("inquiry", ([
                "�����" : "�����������лƺ��������첻�£��ز��£����ʵ��϶������������ʡ�",
                "�ȵ�ʤ" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
                "���Ʒ���ʹ��" : "���Ʒ���ʹ�����뽭����������ɶ������Ӵ�١�����",
                "���͵�" : "���Ʒ���ʹ�����뽭����������ɶ������Ӵ�١�����",
                "�����" : "�����������˰����������Һ��ϴ�˵���㡣",
                "������" : "�ͷ���������ͷ�����Գ�Ӣ�ۺú�������һ��ỵ�˰����Ĵ��¡�",
                "����" : "�ҼҰ����ȴ�ү����ɽ���������š���Ωһ���ˣ��淨������˫��",
        ]));

        setup();

        carry_object("/clone/weapon/sangucha")->wield();
}
