// Code of ShenZhou
//yufeng.c

inherit NPC;

void create()
{
	set_name("���", ({"yu feng", "bee", "feng"}) );
	set("race", "����");
	set("subrace", "�ɳ�");
	set("age", 5);
        set("long", "����һֻ��ɫ���۷䣬��ͷ����ͨ�۷��ö࣬\n"
                    "����ϱ����ü�������֡�\n");
	set("str", 40);
	set("dex", 50);

	set("limbs", ({ "ͷ��", "����", "���", "β��" }) );

	set_temp("apply/attack", 33);
	set_temp("apply/armor", 15);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"��������˷ɹ���������ͷ��ת��һȦ���ַ����ˡ�\n",
		"���ɵ�·�ߵ�һ�����޵�Ұ���ϣ�ææµµ�ز����ۡ�\n",
	 }) );

	setup();
}

