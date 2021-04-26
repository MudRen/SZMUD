// Code of ShenZhou
// maco 4/6/2000
string day_event(){return NATURE_D->outdoor_room_event();}

void init()
{
	add_action("do_yell", "yell");
}

int do_yell(string arg)
{
	string dir;

	if( !arg || arg=="" ) return 0;

	if( arg == "boat" ) arg = "����";

	if( (int)this_player()->query("age") < 16 )
		message_vision("$Nʹ�����̵���������һ������" + 
			arg + "��\n", this_player());
	else if( (int)this_player()->query("neili") > 500 )
		message_vision("$N���˿�����һ����" + arg + 
			"������������ƽ�͵�ԶԶ��"
			"�˳�ȥ��\n", this_player());
	else    message_vision("$N������������Хһ������" + arg + 
			"����\n", this_player());

	if( arg == "����") {		
		check_trigger();
		return 1;
	} else  message_vision("������ԶԶ����һ���������" + arg + "��������\n", this_player());

	return 1;
}

void check_trigger()
{
	object room;
	string myboat;

	if( this_object()->query("exits/enter") ) {
		message("vision", "����һֻ�ɴ��ϵĴ���˵�������������أ������ɡ�\n",
			this_object());
		return;
	}

	if( day_event() == "event_midnight" ) {
		message("vision", "������ʱ��ҹɫ��������ϵĴ��Ҵ�ЪϢ�ˣ��������ߵĺ������б���������\n",
			this_object());
		return;
	}

	if( this_player()->query("family/family_name") != "�һ���") {
		message("vision", "�����ϵĴ�������������һ�޷�Ӧ����\n",
			this_object());
		return;
	}

	myboat = this_object()->query("boat");
		room = new(myboat);

	room->set("yell_trigger", 1);
	this_object()->set("exits/enter", file_name(room) );
	room->set("exits/out", base_name(this_object()));

	message("vision", "һҶ���ۻ�����ʻ�˹���������һ��̤��"
		"����ϵ̰����Ա�˿����¡�\n", this_object() );
	message("vision", "����һ��̤�Ű���ϵ̰����γ�һ������"
		"�Ľ��ݡ�\n", room);

	remove_call_out("on_board");
	call_out("on_board", 15, room);
}

void on_board(object room)
{
	if( !this_object()->query("exits/enter") ) 
		return;

	message("vision", "��������̤�Ű壬������ˮ��һҶ������ʧ�ڴ������\n", this_object() );
	room->set("sail_time", time());
	room->delete("exits/out");
	message("vision", "�����̤�Ű���������˵��һ��������ඡ���"
			"�⽰һ�������������ʻȥ��\n", room );

	this_object()->delete("exits/enter");

	room->arriving();
	room->set_temp("opp", this_object()->query("opposite"));
}
