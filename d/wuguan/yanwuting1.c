#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "���䳡");
       set("long", @LONG
��������ݵ����䳡����ݵ���ÿ��îʱ�����������������ڽ�ͷ��
���������䡣�������ܵı������ϰڷ��ŵ���ǹ������ꪵ�ʮ�˰������
LONG);
       set("exits", ([
//             "northup" : __DIR__"taijie2",
             "west" : __DIR__"yanwuting2",
                          ]));
       set("objects", ([
             __DIR__"npc/xuetu1" : 1,
             "/d/wuguan/npc/mu-ren" : 1,
             ]));
       set("outdoors", "wuguan");
       setup();
}
