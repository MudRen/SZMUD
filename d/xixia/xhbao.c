// Code of ShenZhou
// Room: /d/xixia/xhbao.c

inherit FERRY;

void create()
{
        set("short", "���ͱ�");
        set("long", @LONG
�����������С�����ͱ��������ǻƺӣ�������ɳĮ��ֻ��������һƬ����
�����ޣ�ס���Ƕ��Ǵӹ���Ǩ�ƹ����ģ�����Ծ�Ӫ�ֹ���ƷΪ��, �������֯
��ë��̺����������ÿ���һ��ʮ�壬�����İ��ն�������ڶɹ��ӵ�����ȥ��
�����Ӱ����������������Ƕ������Ž�(yell)�����ӡ�
LONG
        );
        set("cost", 2);
        set("outdoors", "xixia");
        set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"mszhou",
]));

        set("name", "��");
        set("boat", __DIR__"duchuan");
        set("opposite", __DIR__"oldwall");
        set("fjing", 1);
        setup();
}
