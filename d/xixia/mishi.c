// Code of ShenZhou
// RYU 1/5/97
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һƷ�õ����ң�ƽʱֻ������һ���˿��Խ��������Ҳ���ȴ��
����������������ɺ���½�����ë��֯��̺���ĸ����������ţ�;�
��һ�ſ��������������룬��ɫ��ɴ�����ڴ����Ϸ������ߵİ�
���ϰ��ŵ��½������������ѿ���ȥ��Ө��͸����ǽ���Ŵ���ʯ�Ƶ���
�ӣ�һ����������ϵ���ͭ��¯��Ʈ�˹�����
LONG
        );
        set("exits", ([
	"east" : __DIR__"dating" ,
        ]));
	create_door("east","ľ��","west",DOOR_CLOSED);
        set("objects", ([
                __DIR__"npc/yanqing" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
