// Code of ShenZhou
// wu-shi1.c ������ʿ

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������ʿ", ({ "wei shi", "shi", "guard" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"����λ������ʿ�������ּף���ִ������˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
	set("combat_exp", 100000);
        set("shen_type", 1);
	set("attitude", "heroism");

	set("str", 25);
	set("con", 30);
	set("int", 20);
	set("dex", 30);

	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 30);
	set("shen_type", 0);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("sword", 100);
	set_skill("unarmed", 80);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set("no_get", "�㿸����������ʿ");

	setup();

        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}

void init()
{
	object ob1, ob2, ob3;
	string mengzhu, shangshan, fae;
	
	::init();
	if(!( ob1 = find_living("mengzhu")) )
	ob1 = load_object("/clone/npc/meng-zhu");
	mengzhu = ob1->query("winner");

	if(!( ob2 = find_living("shangshan")) )
	ob2 = load_object("/clone/npc/shang-shan");
	shangshan = ob2->query("winner");

	if(!( ob3 = find_living("fae")) )
	ob3 = load_object("/clone/npc/fa-e");
	fae = ob3->query("winner");

	if( this_player()->query("id") == mengzhu ) {
		message_vision(HIY "������ʿ���𳤽�����$N�����󺰣��������꣬���꣬�����꣡\n" NOR, 
		this_player());
	}	
	else if( this_player()->query("id") == shangshan ) {
		message_vision(HIY "������ʿ���𳤽�����$N�����󺰣�����ʹ�ߺã�\n" NOR, 
		this_player());
	}	
	else if( this_player()->query("id") == fae ) {
		message_vision(HIY "������ʿ���𳤽�����$N�����󺰣�����ʹ�ߺã�\n" NOR, 
		this_player());
	}	
}
