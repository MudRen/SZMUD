// outdoor.c zip@hero 2000.1.27 �����ſ�
#include <ansi.h>
#define ID 6001
inherit ROOM;
void create()
{	string *dir=({"��","��"});
	set("short",HIG"���ݴ��"+chinese_number(ID/100)+"��"+dir[ID%2]+NOR);
	set("long",@LONG
������ˮ����(daydream)��[1;37m Բ�ξ�[37;0m��
    һ��Բ�εĵط�.���ĵĻ򲻿��ĵĶ��ղ�����СС��������.
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","daydream");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"