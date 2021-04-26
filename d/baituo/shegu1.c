// Code of ShenZhou
// shegu.c �߹�
// maco 7/15/2000

#include <ansi.h>
#include "room.h"

inherit ROOM;
string long_desc();
int look_mist();

void create()
{
	set("short", "�߹�");
	set("long", (: long_desc :));

	set("exits", ([ 
	    "south" : __DIR__"road5",
	    "northdown" : __DIR__"shegu2",
	]));

	set("item_desc", ([
	"mist" : (: look_mist :),
	"��" : (: look_mist :),
	"����" : (: look_mist :),
	]));

	set("defense", 1);
	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

string long_desc()
{
	string desc;

	if( query("defense") )
	desc  = "�߹��ǰ���ɽ�����ն���ܾ�����Ϣ���������ߣ������������\n"
		"�����ǽ������ɽ�߹ȵ�Ҫ�壬�޴��������ɽ�ڣ��������Ŵ��˵�\n"
		"�߿ڡ���ǰʮ�����ڵ����ش�ݲ���������ð���������(mist)����\n"
		"�������ȿڣ������൱���졣ɽ�ȵ���Χȴ�Ǳ̲�����ż����Щ��\n"
		"��������ڴ˷������ȵ���һ������ȳ�����С����\n";
	else 
	desc  = "�߹��ǰ���ɽ�����ն���ܾ�����Ϣ���������ߣ������������\n"
		"�����ǽ������ɽ�߹ȵ�Ҫ�壬�޴��������ɽ�ڣ��������Ŵ��˵�\n"
		"�߿ڡ���ǰʮ�����ڵ����ش�ݲ�����ɽ�ȵ���Χȴ�Ǳ̲�����ż\n"
		"����Щ����������ڴ˷������ȵ���һ������ȳ�����С����\n";

	return desc;
}

string look_mist()
{
	string desc;
	if( query("defense") ) {
		desc =  RED"һƬѪ��ɫ�����������ϴ���������ð��������֮�У����Ե�ʮ�ֹ��ܡ�\n"NOR;
		if( this_player()->query("family/family_name") == "����ɽ" ) 
		desc += "����ɽׯ�ڵ��½����ܽѣ�ŷ���潫�߳��еľ綾�������ڽ��У�\n"
			"����Ⱥ�ߺ����Ķ�����Ϊ���ϣ��Է���д����߹ȣ������������������صء�\n";
		return desc;
	}
	else return "���������ȿڵĺ���������ȫ��ʧ�ˡ�\n";
}

int valid_leave(object me, string dir)
{
	int i, w;

	if (dir == "northdown") {
		if ( !me->query("baituo/shegu_permit") && query("defense") )
			return notify_fail("�㿴��������ǰ�ĺ�����΢�߽��������ȳ��˱ǣ��о�����Щ��ѣ��\n�������Ǽ�Ϊ�����Ķ�������ǿ��ͨ����\n");

		if ( me->query("family/family_name") == "����ɽ" 
		&& !me->query("baituo/shegu_permit") )
			return notify_fail("������һ�룬����δ��ׯ��ŷ������ɣ����Ǳ��ô��߹ȵúá�\n");
		if ( me->query("baituo/shegu_permit") && query("defense") )
		message_vision("$N����춶������߽����߹ȡ�\n", me);
	}
	return ::valid_leave(me,dir);
}

void reset()
{
	::reset();
	set("no_clean_up", 1);
}
