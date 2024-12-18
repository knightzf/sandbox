package com.addepar.feeds.plaid;

import static org.assertj.core.api.Assertions.assertThat;

import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import javax.annotation.Nullable;
import org.junit.jupiter.api.Test;

/**
 * @author Zhenfei Tai (zhenfei.tai@addepar.com)
 */
public class JsonTest {
  @JsonInclude(JsonInclude.Include.NON_DEFAULT)
  private record MyBean(
      @JsonProperty("id") int id,
      @Nullable @JsonProperty("name") String name,
      @Nullable @JsonProperty("is_valid") Boolean isValid) {}

  @Test
  public void test() throws JsonProcessingException {
    MyBean bean = new MyBean(1, "", null);

    String result = new ObjectMapper().writeValueAsString(bean);

    // assertThat(result).isEqualTo("abc");

    String json = "{\"id\":1, \"name\":\"\"}";
    MyBean myBean = new ObjectMapper().readValue(json, MyBean.class);
    assertThat(myBean.id()).isEqualTo(1);
    assertThat(myBean.isValid()).isEqualTo(null);
    assertThat(myBean.name()).isEqualTo(null);
  }
}
