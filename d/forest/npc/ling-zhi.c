// Code of ShenZhou
// ling-zhi.c ��������

inherit NPC;

void create()
{
	set_name("��������", ({ "lingzhi shangren", "lingzhi", "shangren" }));
//	set("nickname", "");
	set("long", 
"�����������������ɴ��ͷ��һ������Ȼ��ɮñ���Ǹ���ɮ��\n"
"����Ŀ���֮����վ�ű��������˸߳���һ����ͷ��\n");
	set("title", "��ެ����ɮ��");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 23);
	
	set("max_qi", 900);
	set("max_jing", 500);
	set("neili", 850);
	set("max_neili", 850);
	set("jiali", 40);
	set("combat_exp", 330000);

        set_temp("apply/attack",  65);
        set_temp("apply/defense", 65);

	set_skill("force", 95);
	set_skill("dodge", 85);
	set_skill("parry", 95);
	set_skill("hand", 100);
	set_skill("blade", 100);
        set_skill("buddhism", 80);
        set_skill("literate", 30);
	set_skill("dashou-yin", 100);
	set_skill("xueshitiao", 100);

	map_skill("parry", "dashou-yin");
	map_skill("hand", "dashou-yin");
	map_skill("dodge", "xueshitiao");

	prepare_skill("hand", "dashou-yin");

        set("inquiry", ([
            "name" : "�ҵķ��������ǡ�",
            "here" : "��Ҳ������ԭ���ϣ����ϱ������飬��Ǹ��",
	    "����" : "�����Ƿ𷨵�һ�����ɣ��ֳƽ�����ڡ���̵��������ɻ���"
		     "�����ڡ����ڡ����ڡ������ڡ������ڵȡ�������ԭ��������"
		     "�����ڡ��������������ɵ�һ�������������������н����ܷ�"
                     "���ޡ�����ָ�𷨣�����ָ���䡣",
	    "��ެ" : "��ެ�����������������Ա����������ϡ�",
	    "����" : "���·�Ϊ���ڵ��ӣ�ˡ�����ڡ�",
	    "��" : "�����ȥ������ѧϰ����Ȼ���ǵĲ������ڵĲ��������"
		     "�ǹ��ġ�",
	    "������" : "����������ԭ�����ڴ��֡�",
	    "����" : "����д���ָ��Ժ��",
       ]) );

	setup();
	carry_object("/clone/weapon/tongbo")->wield();
	carry_object(__DIR__"obj/dahong-jiasha")->wear();
}
