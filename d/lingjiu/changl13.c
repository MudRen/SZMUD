//room: changl13.c
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
����һ���ǳ������ĳ��ȣ����Ӻ��������û������̴ľ�Ƴɣ�����
������������ͼ�����������ɣ�����ʤ�ա��ذ岻֪����ʲô�������ģ�
�������������Ϣ����ֻ�е���������ģ��ǳ��������������ͨ������
����������--�������ҡ���
LONG
     );

  set("exits",([
      "east" : __DIR__"changl10",
      "west" : __DIR__"xuanbing",      
     ]));
  set("objects",([
     "/kungfu/class/lingjiu/tbjun" : 1,
     ]));
 setup();
 replace_program(ROOM);
}
