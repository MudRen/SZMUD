// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("������", ({ "jin wawa", "jin", "fish" }) );
        set("race", "Ұ��");
        set("age",35);
        set("long", "����������㣬���߷��ߣ�ȫ���ɫ���г�������\n");

        set("attitude", "peaceful");
        
	set("str", 20);
        set("combat_exp", 85000);
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 120);
        set_temp("apply/damage", 2);
        set_temp("apply/armor", 1);

        setup();
}
















