inherit ITEM; 
void create() 
{
set_name("���", ({ "bing chan","hama" }) ); 
set("long","����Ǻ����ϵ����ù��ı��,���������⣨�����壩�ٶ���\n"); 
set("value",10000); 
set("unit","ֻ"); 
}
void init() 
{
if(this_player()==environment()) add_action("do_cure","cure"); 
}
int do_cure()
{
object me;me = this_player();
message_vision("$N������������������ֱ�ҧס��������ָͷ��\n",me); 
me->clear_condition(); 
message_vision("����һ�������������˶�Ѫ�������͵ú�Բ�����ƣ����������ص��Չ�ܰ���ϡ�$N�����˹����������о綾���޴󰭣�\n",me);
destruct(this_object()); 
return 1; 
}
