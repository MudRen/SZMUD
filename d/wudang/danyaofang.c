// Code of ShenZhou
// danyaofang.c ��ҩ��
// xQin 11/00


inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��ҩ��" );
	set("long", @LONG
�������䵱�ɵĵ�ҩ����ֻ������һ���ŵļ��Ӿ�Ȼ���򣬼���(shelf)
��������һ����С�״�ƿ�ӡ�����ҩ�ĺ͵�ҩ���͵����������ܴ棬����Ʈ
����һ�ɵ�����ҩ�㡣
LONG
	);
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"xilang1",
	]));
	
	set("objects", ([
	"/kungfu/class/wudang/yudaiyan.c" : 1,
	
	]));
	
	set("item_desc",([
	"shelf" : "
ֻ������������İ��ż���"HIW"�״�ƿ"NOR"��ƿ���϶��ֱ����ⲻͬ������(tiaozi)��\n",
	"tiaozi" : "
��ϸһ��ԭ��������д�Ķ���ƿ�ڵ�ҩ����

��������	��������	��������	��������
�� �� ��        �� �� ��	�� �� ��	�� �� ��
�� �� ��	�� �� ��	�� �� ��	�� �� ��
�� �� ��	�� �� ��	�� �� ��	�� �� ��
�� �� ��	�� �� ��	�� �� ��	�� �� ��
�� �� ��	�� �� ��	�� �� ��	�� �� ��
��������	��������	��������	�������� \n\n"
	
	]));
	
	setup();
	replace_program(ROOM);
}

