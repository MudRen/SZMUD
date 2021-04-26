// Code of ShenZhou
// bangzhong1.c

inherit NPC;

void create()
{
	set_name("����", 
              ({ "tiecha bangzhong", "bangzhong" }));
        set("title", "�����");
	set("long", 
		"����һ������Ϊ��������������ڡ�\n"
		"�����񲻶�����¶��ɫ��������ʲô��\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 20);
	set("combat_exp", 20000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("cuff", 60);
	set_skill("parry", 60);

        set("inquiry", ([
                "�����" : "�����������лƺ��������첻�£��ز��£����ʵ��϶������������ʡ�",
                "�ȵ�ʤ" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
                "���Ʒ���ʹ��" : "���Ʒ���ʹ�����뽭����������ɶ������Ӵ�١�����",
                "���͵�" : "���Ʒ���ʹ�����뽭����������ɶ������Ӵ�١�����",
                "�����" : "������ڱװ��Ϳ๦�ߣ��ĵð������Ρ�",
                "����" : "�ҼҰ����ȴ�ү����ɽ���������š���Ωһ���ˣ��淨������˫��",
        ]));

	setup();

 	carry_object("/clone/weapon/sangucha")->wield();
}

