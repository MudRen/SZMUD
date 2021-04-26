// Code of ShenZhou
// Room: /d/xixia/spring.c

inherit ROOM;

void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
����ɽ�е�һ����Ȫ��λ���ֳ������ɽ���ϣ���Χ�Ǵ��̵�������������
ɽȪˮ��Ȫ�ۻ�����ӿ�����۳�һ��С̶��С̶���ˮ���������ɽ�£��Ա�һ
��С·ͨ��ɽ�¡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kongdi",
  "northdown" : __DIR__"wangling",
]));
        set("cost", 3);
        set("outdoors", "xixia");
        set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

        setup();
        replace_program(ROOM);
}
