//lx-jing.c

inherit ITEM;
//inherit F_UNIQUE;
void create()
{
	set_name("���������", ({"longxiang jing", "jing"}));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ����ľ��顣\n");
	set("material", "paper");
	set("value", 500);
	
//	::create();
}
void init()
{
	add_action("do_study", "du");
	add_action("do_study", "study");
}
int do_study(string arg)
{
	object me = this_player();
	object ob = this_object();

	if (!id(arg)) return 0;

	if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}
	if(me->query("class") != "lama"){
        	write("��δ����ţ���Ե���ϣ��޷��޳������񷨡�\n");
		return 1;
	}
	if ( me->query_skill("lamaism", 1) < 150){
		write("�Ȿ�������˵̫����ˡ�\n");
		return 1;
	}
	if (!present("longxiang jing", me)) return 0;

	if ( me->query_skill("force", 1) < me->query_skill("longxiang-banruo", 1)*2/3){
		write("��Ļ����ڹ���򲻹���\n");
	return 1;
	}
	if ( me->query("jing") < 60){
		write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
		return 1;
	}
	if (me->is_busy()) {
                write("��������æ���ء�\n");
		return 1;
	}
	if (environment(me)->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
		return 1;
	}

	if ( me->is_fighting() ){ 
                write("���޷���ս����ר�������ж���֪��\n");
		return 1;
	}

	if ( me->query("potential") < 1){
		write("���Ǳ�ܲ�����\n");
		return 1;
	}

	message("vision", me->name() + "��ϸ���ж����������������\n", environment(me), me);

	me->improve_skill("longxiang-banruo", random(me->query_int()*3/2));
	me->receive_damage("jing", 1500 / (int)me->query("int"));
	me->add("potential", -1);

	if(me->query_skill("longxiang-banruo", 1) > 200){
        me->add("potential", -1);
        me->receive_damage("jing", 1500 / (int)me->query("int"));
        }
	write("���ж���������������������ĵá�\n");
	return 1;
}
