//�㳡 by remove 15/09/2001
#include <ansi.h>
inherit ROOM;
void create()
{
     set("short", "���̺���");
     set("long", @LONG
�����ǵ��̵ĺ��ã�������û�п�������ֻ�����ϵ���һյСС���͵ơ��
�ڰ�������Լ����������Ӱ������һ���ˡ�
LONG);
     set("exits", ([
        "out" : __DIR__"dangpu",]));
     set("objects", ([
            __DIR__"npc/xixiashizhe" : 1]));
    set("no_clean_up", 1); 
    setup();
}


