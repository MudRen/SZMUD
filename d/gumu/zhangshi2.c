// Aug 30,2001
// Code by Yujie
// /gumu/zhangshi2.c
// update by April 2001.11.11

#include <room.h>

inherit ROOM;

void create()
{
	set("short","��ȭ��");

	set("long",@LONG
���������ҵ�խ�棬ʯǽ(wall)�Ͽ������ȭ����ָ����ͼ�κ�Ҫ����
ר�Ź���Ĺ������ϰ��Ůȭ���غ�ָ֮�á�
LONG);

	set("item_desc",(["wall" : "�����ͨ����ϰ(yanxi)ǽ�ϵ�Ҫ��������Լ�����Ůȭ���غ�ָ��Ϊ��\n"
		+"���(left)����Ůȭ���ұ�(right)���غ�ָ��\n"]));

	set("exits",([
		"north" : __DIR__"liangongshi2",
		]));

	set("cost",1);
	set("count",0);

	setup();
              
}

void init()
{
	add_action("do_yanxi", "yanxi");
}

int do_yanxi(string arg)
{
	object me = this_player();
	string thisskill="meinu-quan";
	string skilltwo="suhan-zhi";
	int check;

	if ( !arg ) return notify_fail( "��Ҫ����ʲô?\n");
	if ( arg == "wall") return notify_fail("��Ҫ�������(left)�����ұ�(right)��\n");
	if ( arg!="left" && arg!="right") return notify_fail( "��Ҫ����ʲô?\n");
	if ( arg == "right" && me->query("gender") != "Ů��") return notify_fail( "��ѧ�����غ�ָ��\n");

	if ( (int)me->query_skill("literate", 1) < 1){
		write("�����ֶ�����ʶ��ô����ѽ��������ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}

	if (me->is_busy()) return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() ) return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if (me->query_skill("yunu-xinjing",1)<25) {
        write("�����Ů�ľ���Ϊ�������޷����Ҫ���ľ��壡\n");
		return 1;
	}

	if (arg == "left"){
		check = (int)me->query_skill("meinu-quan",1);
		
		if ( check * check * check > (int)me->query("combat_exp") * 10){
			write ("���ʵս���鲻�㣬������ô������Ůȭ��Ҳ�޷���ߣ�\n");
			return 1;
		}
		
		if( me->query_skill("cuff",1) < check * 2/3 )
			return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
		
		if ( check > 200 )
			return notify_fail("ǽ����Ůȭ��Ҫ���ľ����㾡��������գ���Ҳ���ܴ���������ˡ�\n");

		if ( me->query("jing") < 40 || me->query("jingli") < 20 
			|| me->query("neili") <20 ){
	        write("���۵���ǽ�ϵ��ֶ���������ˣ�����ЪϢһ�°ɡ�\n");
			return 1;
		}

		me->receive_damage("jing", 30 ,"����ƣ������");
		me->receive_damage("jingli", 15 ,"����ƣ������");
		me->add("neili", -10 );
		message_vision("$N������ǽ�ϵ�Ҫ����ʼ������Ůȭ���ľ��衭��\n", me);

		me->improve_skill("meinu-quan", me->query_int()/2+me->query_skill("cuff",1)/2);
		write("����ĥ��һ�������Ůȭ������ˡ�\n");
	}

	if (arg == "right"){
		check = (int)me->query_skill("suhan-zhi",1);
		
		if ( check * check * check > (int)me->query("combat_exp") * 10){
			write ("���ʵս���鲻�㣬������ô�����غ�ָҲ�޷���ߣ�\n");
			return 1;
		}
		
		if( me->query_skill("finger",1) < check * 2/3 )
			return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
		
		if ( check > 200 )
			return notify_fail("ǽ���غ�ָ��Ҫ���ľ����㾡��������գ���Ҳ���ܴ���������ˡ�\n");

		if ( me->query("jing") < 40 || me->query("jingli") < 20 
			|| me->query("neili") <20 ){
	        write("���۵���ǽ�ϵ��ֶ���������ˣ�����ЪϢһ�°ɡ�\n");
			return 1;
		}

		me->receive_damage("jing", 30 ,"����ƣ������");
		me->receive_damage("jingli", 15 ,"����ƣ������");
		me->add("neili", -10 );
		message_vision("$N������ǽ�ϵ�Ҫ����ʼ�����غ�ָ���ľ��衭��\n", me);

		me->improve_skill("suhan-zhi", me->query_int()/2+me->query_skill("finger",1)/2);
		write("����ĥ��һ������غ�ָ������ˡ�\n");
	}

/*
	if ((int)me->query_skill(thisskill,1) >= 91){ 
		if ((int)me->query("jingli") < 420 || (int)me->query("neili")<120 ){ 
			write("������״̬���ѣ�û�����������ˡ�\n");
			return 1;
		}
		me->receive_damage("jingli", 400);
		me->add("neili",-100);

		write("�����Ҫ�������Ȼ���ϰ����Ůȭ������ʱ�ջ�ǳ��\n");
		me->improve_skill(thisskill, me->query_skill("cuff",1)*5+me->query_skill(thisskill,1));
	}
	else{
		if ((int)me->query("jingli") < 30 || (int)me->query("qi")<30 ){ 
			write("���۵�������ȭ���������ˡ�\n");
			return 1;
		}
		me->receive_damage("jing", 20);
		me->receive_damage("qi", 20);           
          
		write("�������ǽ�ϵ�Ҫ��Ǳ��������Ůȭ�������������ĵá�\n");
		me->improve_skill(thisskill, me->query_skill("cuff",1)/4+1);
	}

	if (me->query("gender") == "Ů��"){ 
		if( me->query_skill("finger",1)/2 <= me->query_skill(skilltwo,1)/3 )
			return notify_fail("����ͬʱ���������غ�ָ����������ָ�������޷���ߡ�\n" );
		if ((int)me->query_skill(skilltwo,1) >= 91){ 
			if ((int)me->query("jingli") < 220 || (int)me->query("neili")<60 ){
				write("����ͬʱ���������غ�ָ�������Ѿ����������ˡ�\n");
				return 1;
			}
			me->receive_damage("jingli", 200);
			me->add("neili",50);

			write("��ͬʱ��������Ůȭ���������غ�ָ��Ҳ�����ջ�\n");
			me->improve_skill(skilltwo, me->query_skill("finger",1)*3+me->query_skill(skilltwo,1));
			return 1;
		}
		else {
			if ((int)me->query("jingli") < 15 || (int)me->query("qi")< 15 ){
				write("����ͬʱ���������غ�ָ�������Ѿ����������ˡ�\n");
				return 1;
			}        
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);           
  
			write("��ͬʱ��������Ůȭ�����غ�ָ��Ҳ�����ĵá�\n");
			me->improve_skill(skilltwo, me->query_skill("finger",1)/6+1);
			return 1;
		}
	}
*/
	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}
	
