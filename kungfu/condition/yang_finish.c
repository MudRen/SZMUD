//Code of Shenzhou
//yang_finish.c

int update_condition(object me,int duration)
{
    if(duration<1){
      return 0;
      }
    me->apply_condition("yang_finish",duration-1);
      return 1;
}
