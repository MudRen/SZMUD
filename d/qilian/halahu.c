// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��ˮ�����Ź��򶫣���ȥ�������֮Ϊ������������˵�ж��Բ������棬
ÿ�괺���������Է�ţ��ʮͷ�������ƽ������Ȼ��������������ࡣ�����Ƿ�
Բ�˰���Ψһ��ˮԴ��
LONG
        );
        set("exits", ([
                "west" : __DIR__"yumenguan",
                "south" : __DIR__"yumen",
"northeast" : "/d/kunlun/shanlu", 
        ]));

        set("resource/water", 1);

	set("cost", 2);
        set("tjjob", 6);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
