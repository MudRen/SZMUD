// Code of ShenZhou
// yang_xiao.c ����

#include <ansi.h>
inherit NPC;
string check();

void create()
{
	set_name("��ң", ({"yang xiao", "yang"}));
	set("nickname", "������ʹ");
	set("long", 
		"����һ�����������ͷ�ӣ���Ŀ�ΰ������������˵Ķ��ǵ��̣�\n"
		"��ª�ɲ�����ͷ��������֮ɫ���Է��������ϡ�);\n"
	set("age",  45);
	set("gender", "����");
	set("long", "\n");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("shen_type", 0);

	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 300);
	set("combat_exp", 1200000);
	set("score", 400000);


	set_skill("unarmed", 190);
	set_skill("dodge", 190);
	set_skill("parry", 190);
	set_skill("blade", 190);
	set_skill("force", 190);
	set_skill("xiaoyaoyou", 190);
	
	map_skill("dodge", "xiaoyaoyou");

    set("inquiry", ([
        ]) );

	setup();

//	carry_object(__DIR__"obj/")->wear();
}
