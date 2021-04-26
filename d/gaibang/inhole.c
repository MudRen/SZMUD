// Code of ShenZhou
// Room: /d/gaibang/inhole.c
// Date: Haa 96/03/22
inherit ROOM;

int do_say(string);

void create()
{
	set("short", "�����ڲ�");
	set("long", @LONG
�������ݳ�����㳡���ϻ����ڲ���Ҳ��ؤ�����ܵ���ͨ�����ܽ��㴦����
���ﶪ���˸���������������һ�ɳ�����ζ�����������϶���һ��ǳ���Ŀ��
ľ�ƣ�board����
LONG 
	);
	set("exits", ([
		"out" : "d/city/guangchang"
	]));

	set("item_desc",([
		"board"	: "���˵������������á�\n"
	]));

	set("objects",([
		CLASS_D("gaibang") + "/zuo-quan" : 1,
	]));

	set("cost", 1);
	setup();
}

void init()
{
/*	object me = this_player();

	if ( me->query("eat_wan") && me->query("mud_age") < me->query("eat_age")+86400)
	{
	tell_object(me, "���ѷ����裬Ӧ��һ�����ٴη��ã����������𣡣���\n");
	}

	if ( me->query("eat_wan") && me->query("mud_age") > me->query("eat_age")+86400)
	{
	tell_object(me, "��һ����δ�����裬�������𣡣���\n");
	me->add("max_jingli", -100);
	me->add("max_neili", -100);
	me->set("eat_age", me->query("mud_age"));
	}

*/
	add_action("do_say", "say");
}

int do_say(string arg)
{
	object *inv, me = this_player();
	int i, count = 0;

	if( !arg || arg=="" ) return 0;

	inv = all_inventory(environment(me));

/*	for (i=0; i<sizeof(inv); i++) {
		if (inv[i]->is_character() && 
		(string)inv[i]->query("family/family_name") != "ؤ��" ) count ++;
	}
*/
	
	if( (arg=="������·�㲻��ѽ" || arg=="���������������" )
	&& this_player()->query("family/family_name") == "ؤ��")
	{
		write("ֻ����������˵�������Ǳ����ֵܰɣ���������ɡ�\n");
		message("vision", "��������һ��ǽ�������˿�����ԭ���ǵ�Сľ�š�\n", this_player());
		set("exits/down", __DIR__"undertre");

		remove_call_out("close");
		call_out("close", 3, this_object());
		return 1;
	}
	else if ( (arg=="������·�㲻��ѽ" || arg=="���������������" ) 
	&& this_player()->query("family/family_name") != "ؤ��" ) 
	{
		write("ֻ����������˵���������¹��ٱְ��кι�ɣ�\n");
		return 1;
	}

	return 0;
}


void close()
{
        object room = load_object("d/gaibang/undertre");

        message("vision", "Сľ�����ĵĹ����ˡ�\n", this_object() );
        delete("exits/down");
        tell_room(room, "Сľ�����ĵĹ����ˡ�\n");
}

