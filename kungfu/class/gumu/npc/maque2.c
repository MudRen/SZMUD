// maque.c ��ȸ
// /d/gumu/npc/maque.c
// Date: 08/05/2001
// update april 01.08.26

inherit NPC;

void create()
{
        set_name("��ȸ", ({ "ma que", "que", "bird", "maque" }) );
        set("race", "����");
        set("age", 1+random(3));
        set("long", "һֻߴߴ������������ȥ��С��ȸ��\n");
        set("attitude", "peaceful");
        
        set("combat_exp", 100);

        set("chat_chance", 10);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "С��ȸߴߴ�����Ľ��ţ�����ͷ���϶������ˣ�����쳣��\n",
				"С��ȸ̰���ؿ�����䣬��ʱ׼������ȥһ���ڸ��� \n",
        }) );
        
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "С��ȸߴߴߴ��ŭ���ţ�ȫ�����ë������������\n",
        }) );
                
        setup();
}
