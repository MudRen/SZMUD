              
// /d/changan/eroad1.c
// ��һ���޸�
// by bravo
// 02-1-3
// ������ҳ��ַ
// �ļ�����  ����  

inherit ROOM;

void create ()
  {
set("short", "���������");
set("long", @LONG
���ϵ����������е����ţ�·��ż�����������������������ǳ����ǵ���
Ѱ���ĺõط����������߾͵��˶�������ĵط��ˣ������ܿ���ʮ�ֽ�ͷ��
��ˣ�����ˣ������ǴҴҶ�����
LONG);
    set("exits",([
		"east" : __DIR__"eroad2",
		
                "southwest" : __DIR__"wwroad6",
                "northwest" : __DIR__"xfroad6",
	]));
     set("objects", ([
     "/d/quanzhou/npc/butou" : 1,
     ]));
     set("no_clean_up", 0);
     set("cost", 1);

set("outdoors", "changan");


setup();
replace_program(ROOM);
   }
