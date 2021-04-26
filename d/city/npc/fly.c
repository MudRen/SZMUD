// Code of ShenZhou
//fly.c ��Ӭ

inherit NPC;

void create()
{
	set_name("��Ӭ", ({"fly"}) );
	set("race", "����");
	set("subrace", "�ɳ�");
	set("age", 2);
	set("long", "����һֻ����Ĵ�ͷ��Ӭ�������˵ط�����ȥ��\n");
	
	set("str", 10);
	set("dex", 40);

	set_temp("apply/attack", 5);
	set_temp("apply/armor",  5);
	
	set("chat_chance", 8);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"��Ӭ�����˷ɹ�����������ת�˼�Ȧ��\n",
		"��Ӭ����ǰ������ת���ţ��ƺ��������ϴ���ʳ����ζ����ס�ˡ�\n",
		"��Ӭ�˵طɵ����ϣ�����һ�ѹ�ʺ��̰������˱�š�\n"
	 }) );

	setup();
}

void init()
{
	this_object()->set_leader(this_player());
}