// Code of ShenZhou
// Room: /d/heimuya/xiaochuan.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", "С��");
        set("long", @LONG
����һ��С�������Ҳ�����������ĸ��ˡ�һ����
ʮ������������ֳֳ���ݣ����ڴ�β�����س��Ŵ���
LONG
        );


        set("outdoors", "heimuya");
        set("cost", 2);
        set("invalid_startroom", 1);
        setup();
        replace_program(ROOM);
}



