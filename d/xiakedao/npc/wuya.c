//Cracked by Roath
// wuya.c ��ѻ

inherit NPC;

void create()
{
        set_name("��ѻ", ({ "wuya", "bird" }) );
        set("race", "����");
        set("age", 4);
        set("long", "һֻ�ں�������ѻ��\n");
        set("attitude", "peaceful");

        set("combat_exp", 120);

        set("chat_chance", 10);
        set("chat_msg", ({
                "��ѻ���ĵظ¸��ҽ��ţ�����ͷ���Ϸ�����ȥ��\n",
                "��ѻ��Ȼ�������ң������㿴��\n",
	    }) );

        set("chat_msg_combat", ({
                "��ѻ���¡�����һ����ȫ�����ë������������\n",
	    }) );

        setup();
}








