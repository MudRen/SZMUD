#include <ansi.h>
inherit ROOM;
void create()
{	set("short",GRN"�Ҿ���"NOR);
	set("long",@LONG
���������ݴ�־�ͷ��һ��Ҿ����ӣ�������ݴ�ְ��������߳��
���ƵĴ���������е���Щ��ɱ��������ħ������Щ��������ƵĴ���
�ͣ���Щ�Ǹ���һ���ĸ�������Щ�°������˼ң�ȫ�������ﹺ�üҾߣ�
������ҵ�����ǰ��æ�ò����ֺ���
LONG	);
	set("exits",([
	"east" : __DIR__"street0",
	"up" : __DIR__"shop2",
	"down" : __DIR__"bar",
	]));
	set("coor/x",60);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}