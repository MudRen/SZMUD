// Code of ShenZhou
// Jay 8/9/96

inherit ITEM;

void create()
{
        set_name("����", ({"tie chuang","chuang","bed"}));
	set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("long", @LONG 
һ��Ӳ�����������������Ųݵ��ӱ�����һ�ԣ�¶��������������������ּ���
������ţ�

    �Ϸ���ƽ�������ɱ�����飬���Ӻ��ף�����Ӧ��֮����Ψ�Ϸ���
    ���б���춴ˣ�һ��ͨ�쳹���񹦣��������Ϸ�ݹ�ͬ�࣬����С��
    ����֪�Ϸ�֮�ܣ��ຶ��Ҳ���Ƚ��Ϸ��񹦾���Ҫּ������춴ˣ���
    ��С��ϰ֮���е��ݺ����£��Ϸ����Ҳ��ࡣ

    ����֮�ᣬ����ɢ��(sangong)������������ֵ��Ϊ�㡣�����Ϳ���
    �����������ǿ֮���ա�
LONG
);
                set("unit", "��");
                set("material", "steal");
        } 
	setup();
}

void init()
{
 	add_action("do_du", "du");
        add_action("do_du", "study");
}

int do_du(string arg)
{
	int hglevel;

        object me = this_player();
        if (!(arg=="tie chuang" || arg=="chuang" || arg=="bed"))
	return 0;

        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }
        if (!id(arg)) {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if( (int)me->query("jing") < 35) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

	hglevel = me->query_skill("huagong-dafa", 1);
        if( (int)me->query("combat_exp") < (int)hglevel*hglevel*hglevel/10) {
		write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }                 
        if( me->query_skill("huagong-dafa", 1) > 149){
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                return 1;
        }

	if( me->query_skill("huagong-dafa", 1) < 50) {
		write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫���ˣ���ȫ�޷�����\n");
        	return 1;
	}

	if( me->query_skill("force", 1)<10) {
		write("��Ļ����ڹ�����㣬����ѧ�����󷨡�\n");
		return 1;
	}
        if( me->query_skill("huagong-dafa", 1)>29 && 
	(me->query_skill("buddhism",1) || me->query_skill("mahayana", 1)
	|| me->query_skill("taoism",1))) {
                write("��������ķ�ʹ�����ķ��֣���Ը��ѧ�����󷨡�\n");
                return 1;
        }

        me->receive_damage("jing", 35);
	me->improve_skill("huagong-dafa",me->query("int")/3);
	write("���ںڰ������������壬���򻯹��󷨵�Ҫּ��\n");
        return 1;
}                         

