// bayankala.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "���տ���ɽ");
		  set("long",@long
���տ���ɽɽ�Ƶ�ƽ����������ɽ��ڣ�����ͨ���֧���������������
�鲼����ɽ�ŷ�����ȥ���洦�ɼ�һ��������ݵ飬���Ƿ�����������ĺõ�
����Զ��ɢ����һ����������ɹŰ���
long);
		 set("exits",([
"northdown" : __DIR__"shanlu2",
"north"  : "/u/athena/schemeroom2", 
"west" : __DIR__"kekexili",
  "westdown" : "/d/kunlun/hmsz/shenshan1",
]));


set("outdoors", "kunlun");
setup();
}
                                      
int valid_leave(object me, string dir) 
{ 
      object *inv; 
        int i;
        inv = all_inventory(me); 
           if ( dir == "north") {  
                // can not got to any where if they take players  
               for (i=0; i<sizeof(inv); i++) {  
                        if (inv[i]->is_character()) 
                        return notify_fail("�㱳�Ÿ��˻����ȥ��û�ţ�\n");  
                         }
        } 
        return ::valid_leave(me, dir);  
}
