// outdoor.c zip@hero 2000.1.27 �����ſ�
#include <ansi.h>
#define ID 5001
inherit ROOM;
void create()
{	string *dir=({"��","��"});
	set("short",HIG"���ݴ��"+chinese_number(ID/100)+"��"+dir[ID%2]+NOR);
	set("long",@LONG
�����ǿ���(kuxia)��[1;36m���� [1;37m& [1;32mС�ײ� [1;33m��[1;35m����[1;34m�Ͼ�[37;0m��
    ���ǿ���ΪС�ײ˸ǵ������Ͼӣ��Ӵ�С�ײ˲������ˣ��п����Ǿͻ�����������һ�����^_^
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","kuxia");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"