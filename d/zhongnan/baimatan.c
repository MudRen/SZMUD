// Code of ShenZhou
// road: /zhongnan/baimatan.c

inherit ROOM;

void create()
{
        set("short", "����̶");
        set("long", @LONG
���̶Ϊ�����ɽ����һ����һ�����п����ӵ����Ρ�̶����һ���
���䷿�ӻ�Ҫ��İ�ʯͷ����ʯͷ�м����ͷ�ߣ�ʯͷ��ǰ�������ˮ�
�������ڰ��ϡ�������ˮ�е��ǰ��ʯͷ���滹��ʱð��һ������ĭ��
��Զ��ȥ����һƥ�ڿ����ɵ�������˵����˶��д�̶Ϊ����̶��������
һ����᫵�ɽ·��
LONG
        );
        set("outdoors", "zhongnan");

        set("exits", ([
                "northup" : __DIR__"shanlu7",
                "west"  : "/u/athena/schemeroom1", 
        ]));

        set("cost", 1);
        set("fjing", 1);
        setup();
}

int valid_leave(object me, string dir)  
{ 
      object *inv; 
        int i;  
        inv = all_inventory(me);  
           if ( dir == "west") {  
                // can not got to any where if they take players  
               for (i=0; i<sizeof(inv); i++) {  
                        if (inv[i]->is_character()) 
                        return notify_fail("�㱳�Ÿ��˻����ȥ��û�ţ�\n");  
                          } 
         } 
        return ::valid_leave(me, dir);  
}
