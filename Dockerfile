ARG CONTAINER_IMAGE_REGISTRY

ARG BUILDER_CONTAINER_IMAGE=${CONTAINER_IMAGE_REGISTRY:+${CONTAINER_IMAGE_REGISTRY}/}tools-cpp-builder

ARG CMAKE_PROJECT_NAME=worker

FROM ${BUILDER_CONTAINER_IMAGE} AS build

FROM scratch

COPY --from=build /var/workspace/build/bin /

ARG PORT=5555

ENV SERVICE_PORT=${PORT}

EXPOSE ${PORT}

ENTRYPOINT [ "/worker" ]