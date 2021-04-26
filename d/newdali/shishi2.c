// Code of ShenZhou
// Room: /dali/shishi2.c
// AceP

inherit ROOM;

int do_gui();
int do_ketou();
int do_leave();

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��ʯ����������һ�������ɵ���Ůʯ��(shixiang)������ʯ����д������֣�
���ǡ�ׯ�ӡ��еľ��ӣ��ʷ�Ʈ�ݣ����Ǽ�ǿ����������д�ɣ�ÿһ�ֶ�����ʯ��
����磬��ĩ�ǡ���ң��Ϊ��ˮ���顣���������£��˼�����Ҳ����������ǰ����
������(putuan)������и��¶��ţ��Ҳ��ƺ���һ��ʯ��(shijie)��
LONG );

	set("exits", ([
		"left"  : __DIR__"shishi3",
	]));

	set("item_desc", ([
		"shixiang" :
"����һ������ʯ�񣬺�����һ����С������һ�����Ƶĳ�����΢΢�������ֳ�һ��\n"
"�������������һ������ӨȻ�й⣬��ɷ������������úڱ�ʯ���ɣ��۹���\n"
"�������˻��ˡ�",
		"putuan" : "һ��һС�������ţ�����ǹ��˹���֮�ã�С���ǹ��˿�ͷ֮�á�\n",
		"shijie" : "һ��ʯ�ף������Ŀ�����ͷ����֪ͨ���δ��������ǳ�ȥ(leave)��·�ɡ�\n",
	]));
	set("book_count", 1);
	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_gui", "gui");
	add_action("do_ketou", "ketou");
	add_action("do_leave", "leave");
}

int do_gui()
{
	object me;
	me=this_player();

	if (me->query_temp("in_putuan")) {
		tell_object(me,"���Ѿ������ˡ�\n"); }
	else {
		tell_object(me,"���ڴ������Ϲ��¡�\n");
		me->set_temp("in_putuan",1);}
	return 1;
}

int do_ketou()
{
	object me, ob;
	me=this_player();

	if (me->query_temp("in_putuan")) 
	{
		if (me->query_temp("ketou_times")>100 && me->query("int")>25) {
			if (query("book_count") > 0){
			tell_object(me,
"��ĵ�ͷ�����ˣ�ͻȻ����С������һ����Ѳ��Ѿ����ѣ�¶���������\n"
"�����Ǹ������һ������������д�ţ���ȿ���ǧ�飬�Ե��������ߣ������޻ڡ�\n"
"�˾�������ң���书��Ҫ��ÿ������������ϰ��\n"
"��õ��˱�ڤ�ؼ�������\n");
			ob=new(__DIR__"obj/beiming-miji");
			ob->move(me);
			add("book_count", -1);
			me->set("got_beiming",1);
			me->set_temp("got_miji",1);
			me->delete_temp("ketou_times");
			return 1;
			}
			else {
			tell_object(me,
"��ĵ�ͷ�����ˣ�ͻȻ����С������һ����Ѳ��Ѿ����ѣ���������ʲôҲû�С�\n");
			me->delete_temp("ketou_times");
			return 1;
			}
		}
		if (!me->query_temp("ketou_times")) {
			tell_object(me,"����С�����Ͽ��˸�ͷ��ͻȻ��������˫�ŵ�Ь���Կ����֣�\n"
"�ң�����ǧ�飬�������ߡ������������������޻ڡ�\n");
			me->set_temp("ketou_times",1); }
		else {
			tell_object(me,"����˸�ͷ��\n");
			me->add_temp("ketou_times", 1);	
		}
		return 1;
	}
	return 0;
}

int do_leave()
{
	object me;
	me=this_player();

	tell_object(me,
"������������ʯ���ϣ��߳�һ�ٶಽ��ת�������䣬��������Խ��Խ���ˮ������\n"
"���˶��ٶಽ��ˮ�����������ǰ�沢�й���͸�룬�ߵ���ͷ��ǰ���Ǹ���������\n"
"��С��������һ��������ŭ����ӿ��ˮ���ļ�������һ���󽭡������˳�ȥ������\n"
"�˽��ߡ�\n");
	me->move(__DIR__"jb1");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("ketou_times") >= 0) {
		me->delete_temp("in_putuan");
		me->delete_temp("ketou_times"); }
	return ::valid_leave();
}
