// squirrel ����
// /d/jueqing/npc/squirrel.c
// Date: 08/2001

inherit NPC;

void create()
{
        set_name("����", ({ "song shu","squirrel","shu"}) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ������ȥ��С����\n");
        set("attitude", "peaceful");
        set_weight(300);

        set("combat_exp", 10);

        set("chat_chance",8);
		set("chat_msg", ({
			(: this_object(), "random_move" :),
			"С����һ���������ǰ���������Ӷ����㡣\n",
			"С�����Ź���'��������'��ҧ�˼��ڡ�\n",
			"С������һ����'��'��һ������������\n",
			}) );
		
		set_temp("apply/attack", 5);
		set_temp("apply/dodge",20);
		set_temp("apply/armor", 1);	
		
		setup();
}
