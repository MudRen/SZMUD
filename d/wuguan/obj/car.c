/*-------------------------------------------------------------
** �ļ���: car.c
** Copyright (c) 2000-2001
** ������: ��ݹ�����
** ��  ��: 2001/08/13
** ��  ��: ��
**-----------------------------------------------------------*/

#include <ansi.h>
inherit ITEM;

void arrive(object, object, object, string, string, string);
int do_hire(string arg);

void create()
{
        set_name(HIY"��ݴ�"NOR, ({ "wuguan dache", "dache", "carriage"}) );
	set_weight(500000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", @LONG
����һ������ƥ�����ŵĴ󳵡���ǰ������һ���ϳ�����������
ֻ���ޡ������ﲻͣ�źߺ���ʲô���Ĳ����ɵ��������š�

����������ˣ�ӭ����˵�����⳵��������ݰ������ġ�����
ȥ(qu)���Ҷ���������ȥ�����ݣ����ݣ�Ȫ�ݣ�̩ɽ�����֣�����
�����ڣ��䵱�����ң��������ģ���ɽ�����ޣ�ѩɽ�����ݣ���
ɽ������ɽ�������¿��Ĺ�Ĺ��
LONG
	);
		set("value", 1000000);
		set("material", "steel");
		set("no_get",1);
	}
	setup();
}