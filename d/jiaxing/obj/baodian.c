// Code of ShenZhou
// kuihua.c ��������
// Jay 8/12/96

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}

void create()
{
        set_name("��������", ({ "kuihua baodian", "baodian", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��������������صġ��������䡷��\n");
                set("value", 5000);
                set("material", "paper");
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");

        }
}

int do_du(string arg)
{
	mapping skl;
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int pxlevel; 
	int neili_lost;
	int i,j;
	string *sname;

	if (!(arg=="kuihua baodian" || arg == "baodian" || arg == "book"))
	return 0;

        if (where->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

/*        if(!arg || !objectp(ob = present(arg, me)) ){
                write("��Ҫ��ʲô��\n");
                return 1;
        }
*/
        if (!id(arg)) {	
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        switch(random(3)) {
          case 0:
        message("vision", me->name() + "͵͵��������һ�����ڶ���\n", environment(me), me);
              break;
          case 1:
        message("vision", me->name() + "�߶����ɧ��Ū�ˣ�������ģ��Ů�ˡ�\n", environment(me), me);
              break;
          case 2:
        message("vision", me->name() + "�߶���߰�����Ť��Ťȥ��\n", environment(me), me);
              break;
        }
        if( (int)me->query("jing") < 25 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

        if( (int)me->query("neili") < 25) {
		write("�������������޷�������ô������书��\n");
                return 1;
        }

        pxlevel = me->query_skill("pixie-jian", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }
	if(pxlevel <90) {
		write("���ж���һ��������Ƿ���������˵�Ķ������̫���ˡ�\n");
		return 1;
        }

	skl = me->query_skills();
	sname  = keys(skl);

        for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]] < 80) {
			write("���еĹ���̫���ˣ�Ӱ��������ޡ�\n");
			return 1;
		}
		if (skl[sname[i]] <100) j++;
		if (j>2) {
			write("�㲻��ǿ�Ĺ���̫�࣬Ӱ��������ޡ�\n");
			return 1;
		}
	}

        if( pxlevel > 199){
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                return 1;
        }

        me->receive_damage("jing", 25);
	me->set("neili",(int)me->query("neili")-25);
        me->improve_skill("pixie-jian", (int)me->query_skill("literate", 1)/4+1);
        write("���ж����������䡷�������ĵá�\n");
        return 1;
}

