// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
void create()
{
	set_name("�����޶�����", ({ "du jing", "jing" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long",
"\n                 �����޶�����\n\n"
"��������Ϊ���ޱ��䣬���Դ˾�����������ҩ��˽�����ˣ�����Ϊ��ʦ���桢\n"
"����ʦ�š�����ʦ֮ͽ����������أ�����ӱ�����֮�����˳��б����ߣ���\n"
"���Ӽ�һ��ɱһ������ʮ��ɱʮ�����ϲ���˽�ı��ű����߹���������\n\n"
"�����������������������������������������������������������ɡ���\n"
"���ɺ�ҩ��\n"
"���÷�����ҩ�����ˮ�����˺��£�pour yao in <����>����\n"
"��ҩ�ԣ�����������ʹ�˻��ʡ���������ǿ�ߣ�ҩЧ���ԡ�\n\n"
"�����ĵ���\n"
"���÷�����Ϊ����ʹ�ã�throw <target>����\n"
"��ҩ�ԣ�����������ƻ𵯣�ʹ��Ƥ�������������漴���뼡�⡣\n"
"  �Ʒ�������Ǻ��ߵ�������˿����ɡ���make lianxin dan����\n\n"
"�������롿\n"
"���÷�����Ϊ����ʹ�ã�throw <target>����\n"
"��ҩ�ԣ����룬ι�о綾���粻����ҩ��������֮�ǡ�\n"
"  �Ʒ������廨����ߵ�������˿�ȴ�ɡ���make bilin zhen����\n\n"
"����ң��Цɢ��\n"
"���÷���������ʹ�ã�tan<��> <target>  ����\n"
"��ҩ�ԣ���ɫ��ζ���ۣ�ɱ���޾ȡ���ǿ���ܰѶ���أ���ᷴ���亦��\n"
"  �Ʒ����ñ��ű������񲧣�������Ž��嶾�����ߵ���ɳ��ǡ�Ы�ӿǣ�\n"
"        ����˿�����ǣ�����Ƴɡ�\n\n"
"�������ѡ�\n"
"  ȡ�����ӻ��Ե����߿��м��������У�squeeze[or ji] snake to bo����\n"
"  �÷���ֱ��ͿĨ�������ϣ�coat[or tu] <weapon >����\n\n"
"������ɢ��\n"
"���÷����̷���eat san����\n"
"��ҩ�ԣ�Ϊ���Ŷ��Ž�ҩ���ɽ����ĵ������޶���֮����\n"
"    \n");
		set("value", 300);
		set("material", "paper");
		set("skill", ([
                        "name": "poison",      // name of the skill
                        "exp_required": 0,      // minimum combat experience req
                        "jing_cost":    20,     // jing cost every time study th
                        "difficulty":   10,     // the base int to learn this sk
                        "max_skill":    30      // the maximum level you can lea
                ]) );
        }
	setup();
}
