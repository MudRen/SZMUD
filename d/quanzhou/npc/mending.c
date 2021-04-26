// Code of ShenZhou
// mending.c ����Ŷ�
// qfy July 30, 1996
inherit NPC;

void create()
{
	set_name("����Ŷ�", ({ "men ding", "ding" }));
	set("long", "�����ø�ͷ�����ǳ���׳��\n");
	set("gender", "����");
	set("age", 25);

	set_skill("unarmed", 20);
	set_skill("dodge", 30);
	set_skill("parry", 20);
	set_skill("stick", 20);
	set_skill("staff", 20);
	set_skill("sword", 20);
	set_skill("blade", 20);	
        set_temp("apply/attack", 8);
        set_temp("apply/defense", 8);
        set_temp("apply/damage", 5);


	set("combat_exp", 8000);
	set("shen_type", 1);
	setup();

	switch( random(4) )
        {
                case 0:
                       carry_object("/d/city/obj/gangjian")->wield();
                       break;
                case 1:
                       carry_object("/d/city/obj/gangdao")->wield();
                       break;
                case 2:
                       carry_object("/d/xingxiu/obj/gangzhang")->wield();
                       break;
                case 3:
                       carry_object("/d/city/obj/zhubang")->wield();
		       break;		
	}
}
