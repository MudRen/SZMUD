// Code of ShenZhou
void init()
{
	object maskman, obj, me=this_player();

	if ( interactive(me) && living(me)) {	
		   if (random(10) == 3 && time() > me->query("mp_job_time") + 180 ) {
			if (obj = present("ling pai",me) && obj->query_temp("owner") == me->query("id"))
				return;
			message_vision("ͻȻͷ����һ�󾢷磬һ�����������������������\n", me);
			maskman = new(__DIR__"npc/maskman");
			maskman->move(environment(me));
		   }
	}
}
/*
int valid_leave(object me, string dir)
{
	if ( present("mengmian ren", environment(me)) )
		return notify_fail("����������˵�����ߣ���û�������ף�\n");

	return ::valid_leave(me, dir);
}
*/

