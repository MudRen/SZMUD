// by remove /16/09/2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���鷿");
        set("long", @LONG
����һ���ǳ����Ĵ��鷿����ǽһ����һ�ŵ�����ϣ����������
�������顣�鷿����ڷ���һ�Ŵ�ľ����һЩľ���ʣ�����������޷���
��������ʫ��ѡ����
LONG);
        set("exits", ([              
             "north" : __DIR__"qianting"]));
        set("objects", ([
                    __DIR__"obj/sanzijing" : 2,                   
                    __DIR__"obj/qianziwen" : 2,]));
        set("no_steal", 1);
        set("no_hit", 1);
        set("cost", 0);
        setup();
 
//replace_program(ROOM);
}

int valid_leave(object me,string dir)
{
        object *inv;
        int i, aa, bb;      
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++)
         {
          if ((string)inv[i]->query("id")=="sanzi jing") aa++;
          if ((string)inv[i]->query("id")=="qianzi wen") bb++;       
         }          
         if ( (aa + bb) >1 )
                     return notify_fail("��̫�����ˣ����ܴ�����ô���顣\n");
         return ::valid_leave(me, dir);

}




